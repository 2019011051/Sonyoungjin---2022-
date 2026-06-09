% =========================================================================
% make_plate.m
% 직사각형 PEC 판 모델 생성 (PoFacets 호환 포맷)
%
% 논문 조건: a=2lambda, b=4lambda, 판이 xz평면(y=0)
%   x: -b/2 ~ b/2  (leading/trailing edge 방향)
%   z: -a/2 ~ a/2  (side edge 방향)
%   y: 0           (판 법선 +y 방향)
%
% 사용법:
%   >> make_plate          % 기본값으로 실행
%   >> make_plate          % ds 변경 후 실행
%
% 출력: plate_NxM.mat  (coord, facet, a, b, lambda, freq, k)
% =========================================================================
clear; clc;
 
%% ── 파라미터 설정 ────────────────────────────────────────────────────────
lambda = 1.0;       % 파장 [m]
a      = 2.0;       % z방향 길이 [m] = 2*lambda
b      = 4.0;       % x방향 길이 [m] = 4*lambda
 
ds     = 0.02;      % 격자 간격 [m] (lambda 단위)
                    %   0.05 lambda ->  6400 패싯 (기존)
                    %   0.02 lambda -> 40000 패싯 (개선)
                    %   0.01 lambda ->160000 패싯 (고해상도)
 
%% ── 격자 생성 ────────────────────────────────────────────────────────────
x_vec = -b/2 : ds : b/2;   % x 격자점
z_vec = -a/2 : ds : a/2;   % z 격자점
 
Nx = length(x_vec);         % x방향 점 수
Nz = length(z_vec);         % z방향 점 수
nvert = Nx * Nz;            % 총 정점 수
ntria = 2 * (Nx-1) * (Nz-1); % 총 삼각형 수
 
fprintf('격자 간격: %.4f lambda\n', ds/lambda);
fprintf('x 격자점: %d  z 격자점: %d\n', Nx, Nz);
fprintf('총 정점: %d  총 패싯: %d\n', nvert, ntria);
 
%% ── coord 생성 ───────────────────────────────────────────────────────────
% 인덱스 규칙: idx(ix, iz) = (ix-1)*Nz + iz  (1-based)
coord = zeros(nvert, 3);
for ix = 1:Nx
    for iz = 1:Nz
        idx = (ix-1)*Nz + iz;
        coord(idx, 1) = x_vec(ix);  % x
        coord(idx, 2) = 0.0;        % y = 0 (평면)
        coord(idx, 3) = z_vec(iz);  % z
    end
end
 
%% ── facet 생성 ───────────────────────────────────────────────────────────
% 각 사각형 셀을 2개의 삼각형으로 분할
% 정점 번호 (1-based):
%   v_bl = (ix-1)*Nz + iz      (bottom-left)
%   v_br = (ix-1)*Nz + iz+1    (bottom-right, z+1)
%   v_tl =  ix   *Nz + iz      (top-left,    x+1)
%   v_tr =  ix   *Nz + iz+1    (top-right)
%
% 삼각형 1: v_bl, v_br, v_tl  -> 노말 방향 확인 필요
% 삼각형 2: v_tl, v_br, v_tr
%
% PoFacets 노말 방향: N = -cross(B,A) where A=v2-v1, B=v3-v2
% 판이 y=0, 노말이 +y가 되려면:
%   삼각형 1: v_bl->v_tl->v_br  (CCW when viewed from +y)
%   삼각형 2: v_tl->v_tr->v_br
 
% ilum_flag = 0 (양면 조명)
% Rs = 0 (PEC) -> 5열로 바로 생성
 
facet = zeros(ntria, 5);
tri_idx = 0;
 
for ix = 1:Nx-1
    for iz = 1:Nz-1
        v_bl = (ix-1)*Nz + iz;
        v_br = (ix-1)*Nz + iz + 1;
        v_tl =  ix   *Nz + iz;
        v_tr =  ix   *Nz + iz + 1;
 
        % 삼각형 1: v_bl, v_tl, v_br
        tri_idx = tri_idx + 1;
        facet(tri_idx, :) = [v_bl, v_tl, v_br, 0, 0];
 
        % 삼각형 2: v_tl, v_tr, v_br
        tri_idx = tri_idx + 1;
        facet(tri_idx, :) = [v_tl, v_tr, v_br, 0, 0];
    end
end
 
%% ── 노말 방향 검증 ───────────────────────────────────────────────────────
% 첫 패싯의 노말이 +y인지 확인
v1 = coord(facet(1,1), :);
v2 = coord(facet(1,2), :);
v3 = coord(facet(1,3), :);
A_vec = v2 - v1;
B_vec = v3 - v2;
N_raw = -cross(B_vec, A_vec);  % PoFacets 방식
N_unit = N_raw / norm(N_raw);
fprintf('첫 패싯 노말: [%.3f %.3f %.3f] ', N_unit);
if N_unit(2) > 0.9
    fprintf('-> +y 방향 OK\n');
else
    fprintf('-> 경고: 노말 방향 이상! 삼각형 순서 확인 필요\n');
    % 노말이 -y면 v2, v3 순서 바꾸기
    facet(:, [2,3]) = facet(:, [3,2]);
    fprintf('   자동 수정 완료\n');
end
 
%% ── 주파수 파라미터 ──────────────────────────────────────────────────────
c      = 3e8;
freq   = c / lambda;           % [Hz]
k      = 2*pi / lambda;        % [rad/m]
 
%% ── 저장 ─────────────────────────────────────────────────────────────────
Nx_cell = Nx - 1;
Nz_cell = Nz - 1;
fname = sprintf('plate_%dx%d.mat', Nx_cell, Nz_cell);
 
save(fname, 'coord', 'facet', 'a', 'b', 'lambda', 'freq', 'k', 'ds');
fprintf('저장 완료: %s\n', fname);
fprintf('  coord: %d x 3\n', size(coord,1));
fprintf('  facet: %d x 5  (5열 = Rs 포함)\n', size(facet,1));
fprintf('  ds = %.4f lambda\n', ds);
 
%% ── 간단 시각화 (선택) ───────────────────────────────────────────────────
figure;
patch('Vertices', coord, ...
      'Faces',    facet(:,1:3), ...
      'FaceColor','cyan', 'EdgeColor','k', 'EdgeAlpha', 0.3);
axis equal; grid on;
xlabel('x [m]'); ylabel('y [m]'); zlabel('z [m]');
title(sprintf('Plate model: %d facets, ds=%.4f\\lambda', ntria, ds));
view(3);