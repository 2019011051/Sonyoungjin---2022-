% =========================================================================
% run_mono_PO.m
% Monostatic PO RCS 계산 실행 스크립트
%
% 사용법:
%   MATLAB 커맨드창에서:  >> run_mono_PO
%   또는 배치/자동화 환경에서 직접 호출
%
% D:\Claude_POPTD\ 폴더에서 실행
% =========================================================================
clear; clc;
addpath(fileparts(mfilename('fullpath'))); % 현재 폴더를 경로에 추가

%% ══════════════════════════════════════════════════════════════════════════
%  [1] 모델 로드
%      coord : [nvert x 3]  정점 좌표 (x, y, z) [m]
%      facet : [ntria x 5]  패싯 (v1, v2, v3, ilum_flag, Rs)
%      matrl : cell array   재료 데이터 (rsmethod=2일 때 필요)
% ══════════════════════════════════════════════════════════════════════════
model_file = 'plate_200x100.mat';   % ← 모델 파일 경로

if exist(model_file, 'file')
    load(model_file, 'coord', 'facet');
    facet = [double(facet), zeros(size(facet,1), 1)];
    fprintf('Model loaded: %s  (%d verts, %d triangles)\n', ...
        model_file, size(coord,1), size(facet,1));
else
    error('모델 파일을 찾을 수 없습니다: %s', model_file);
end

% matrl 없는 경우 기본값 (rsmethod=1 사용 시 필요 없음)
if ~exist('matrl', 'var')
    matrl = repmat({'PEC', []}, size(facet, 1), 1);
end

%% ══════════════════════════════════════════════════════════════════════════
%  [2] 계산 파라미터 설정
% ══════════════════════════════════════════════════════════════════════════

%── 주파수 ────────────────────────────────────────────────────────────────
freq = 0.3;         % [GHz]

%── 각도 범위 (Monostatic) ────────────────────────────────────────────────
tstart =   90;       % theta 시작 [deg]
tstop  = 90;       % theta 종료 [deg]
delt   =   1;       % theta 간격 [deg]

pstart =   0;       % phi 시작 [deg]
pstop  =   90;       % phi 종료 [deg]  (phi-cut: pstart==pstop)
delp   =   0.5;       % phi 간격 [deg]  (phi-cut이면 값 무관)

%── 입사 편파 ─────────────────────────────────────────────────────────────
i_pol = 1;          % 1 = theta 편파,  2 = phi 편파

%── Taylor 급수 파라미터 (특이점 처리) ───────────────────────────────────
Lt = 1.0;          % 특이점 판별 임계값 (PoFacets 기본값)
Nt = 20;            % 급수 항수

%── 표면 거칠기 (확산 성분, 매끄러운 면이면 0) ────────────────────────────
corr    = 0;        % 상관 거리 [m]
std_dev = 0;        % 높이 표준편차 [m]

%── 반사계수 방법 ─────────────────────────────────────────────────────────
rsmethod = 1;       % 1 = Rs (패싯 col5 값 사용)
                    % 2 = 재료 데이터 사용 (matrl 필요)

%── Ground plane ──────────────────────────────────────────────────────────
useground = 0;      % 0 = 사용 안함
pec       = 1;      % 1 = PEC 지면, 0 = 유전체 지면
relpermit = 4.0;    % 유전체 지면 상대 유전율 (pec=0일 때)

%── 대칭면 ────────────────────────────────────────────────────────────────
usesymmetry = 0;    % 0 = 사용 안함
symplanes   = [];

%% ══════════════════════════════════════════════════════════════════════════
%  [3] PO 계산 실행
% ══════════════════════════════════════════════════════════════════════════
fprintf('\n========================================\n');
fprintf(' Monostatic PO RCS Calculation\n');
fprintf('========================================\n');
fprintf(' freq     = %.3f GHz\n', freq);
fprintf(' theta    = %g ~ %g deg (step %g)\n', tstart, tstop, delt);
fprintf(' phi      = %g ~ %g deg\n', pstart, pstop);
pol_str = {'theta','phi'};
fprintf(' pol      = %s\n', pol_str{i_pol});
fprintf(' rsmethod = %d\n', rsmethod);
fprintf('----------------------------------------\n');


tic;
[Sth, Sph, theta_mat, phi_mat, Ethscat, Ephscat] = CalcMono_nogui( ...
    coord, facet, matrl, ...
    freq, ...
    tstart, tstop, delt, ...
    pstart, pstop, delp, ...
    i_pol, Lt, Nt, ...
    corr, std_dev, ...
    rsmethod, ...
    useground, pec, relpermit, ...
    usesymmetry, symplanes);
elapsed = toc;
fprintf('Elapsed time: %.2f sec\n', elapsed);

%% ══════════════════════════════════════════════════════════════════════════
%  [4] 결과 저장
% ══════════════════════════════════════════════════════════════════════════
[~, mname, ~] = fileparts(model_file);
outname = sprintf('RCS_%s_%.3fGHz_pol%d', mname, freq, i_pol);

% .mat 저장
save([outname '.mat'], 'Sth', 'Sph', 'theta_mat', 'phi_mat', ...
    'Ethscat', 'Ephscat', 'freq', 'i_pol');
fprintf('Saved: %s.mat\n', outname);

% .csv 저장 (phi-cut일 때: theta vs Sth, Sph)
ip = size(Sth, 1);
it = size(Sth, 2);
if ip == 1
    % phi-cut: theta sweep
    theta_vec = theta_mat(1, :).';
    T = table(theta_vec, Sth(1,:).', Sph(1,:).', ...
        'VariableNames', {'theta_deg', 'RCS_th_dBsm', 'RCS_ph_dBsm'});
    writetable(T, [outname '.csv']);
    fprintf('Saved: %s.csv\n', outname);
elseif it == 1
    % theta-cut: phi sweep
    phi_vec = phi_mat(:, 1);
    T = table(phi_vec, Sth(:,1), Sph(:,1), ...
        'VariableNames', {'phi_deg', 'RCS_th_dBsm', 'RCS_ph_dBsm'});
    writetable(T, [outname '.csv']);
    fprintf('Saved: %s.csv\n', outname);
end

%% ══════════════════════════════════════════════════════════════════════════
%  [5] 결과 플롯 (선택)
% ══════════════════════════════════════════════════════════════════════════

% 이론 정규화 기준값 (논문 식 20)
% sigma_PO_normal = 4*pi*a^2*b^2/lambda^2
C_light = 3e8;
lambda  = C_light / (freq * 1e9);
a_plate = 2 * lambda;   % z방향 길이 [m]
b_plate = 4 * lambda;   % x방향 길이 [m]
sigma_normal_dBsm = 10*log10(4*pi * a_plate^2 * b_plate^2 / lambda^2);
fprintf('정규화 기준 sigma_PO = %.2f dBsm\n', sigma_normal_dBsm);

if ip == 1
    figure;
    plot(theta_mat(1,:), Sth(1,:) - sigma_normal_dBsm, 'b-',  'LineWidth', 1.5); hold on;
    plot(theta_mat(1,:), Sph(1,:) - sigma_normal_dBsm, 'r--', 'LineWidth', 1.5);
    grid on;
    xlabel('\phi (deg)');
    ylabel('Normalized RCS (dB)');
    ylim([-70 10]);
    title(sprintf('%s  %.3f GHz  \\phi=%g deg  [Normalized by \\sigma_{PO}^{normal}]', mname, freq, pstart));
    legend('\theta-pol (E-pol)', '\phi-pol (H-pol)');
end

if it == 1
    figure;
    plot(phi_mat(:,1), Sth(:,1) - sigma_normal_dBsm, 'b-',  'LineWidth', 1.5); hold on;
    plot(phi_mat(:,1), Sph(:,1) - sigma_normal_dBsm, 'r--', 'LineWidth', 1.5);
    grid on;
    xlabel('\phi (deg)');
    ylabel('Normalized RCS (dB)');
    ylim([-70 10]);
    title(sprintf('%s  %.3f GHz  \\theta=%g deg  [Normalized by \\sigma_{PO}^{normal}]', mname, freq, tstart));
    legend('\theta-pol (E-pol)', '\phi-pol (H-pol)');
end