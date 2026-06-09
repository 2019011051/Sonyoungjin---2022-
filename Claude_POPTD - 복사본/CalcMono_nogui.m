function [Sth, Sph, theta_out, phi_out, Ethscat, Ephscat] = CalcMono_nogui( ...
    coord, facet, matrl, ...
    freq, ...
    tstart, tstop, delt, ...
    pstart, pstop, delp, ...
    i_pol, ...
    Lt, Nt, ...
    corr, std_dev, ...
    rsmethod, ...
    useground, pec, relpermit, ...
    usesymmetry, symplanes)
% =========================================================================
% CalcMono_nogui.m
% GUI 없는 Monostatic PO RCS 계산 함수
%
% 원본: PoFacets 4.5, CalcMono.m (Prof. David C. Jenn, NPS)
% 수정: GUI 코드 제거, 함수 인자로 파라미터 수신
%
% -------------------------------------------------------------------------
% 입력 인자:
%   coord      : [nvert x 3] 정점 좌표 행렬 (x, y, z) [m]
%   facet      : [ntria x 5] 패싯 행렬
%                  col 1-3: 정점 인덱스
%                  col 4  : 조명 플래그 (1=외부면만, 0=양면)
%                  col 5  : 표면 저항률 Rs (free space 기준 정규화)
%   matrl      : 재료 셀 배열 (rsmethod=2일 때 사용)
%   freq       : 주파수 [GHz]
%   tstart     : theta 시작각 [deg]
%   tstop      : theta 종료각 [deg]
%   delt       : theta 간격 [deg]
%   pstart     : phi 시작각 [deg]
%   pstop      : phi 종료각 [deg]
%   delp       : phi 간격 [deg]
%   i_pol      : 입사 편파 (1=theta pol, 2=phi pol)
%   Lt         : Taylor 급수 특이점 판별 임계값 (보통 0.01)
%   Nt         : Taylor 급수 항수 (보통 10)
%   corr       : 표면 상관 거리 [m] (확산 성분용, 0이면 무시)
%   std_dev    : 표면 높이 표준편차 [m] (확산 성분용, 0이면 무시)
%   rsmethod   : 반사계수 방법 (1=Rs 사용, 2=재료 데이터 사용)
%   useground  : 지면 반사 사용 여부 (0=사용 안함, 1=사용)
%   pec        : 지면 PEC 여부 (useground=1일 때만 유효, 1=PEC, 0=유전체)
%   relpermit  : 지면 상대 유전율 (pec=0일 때만 유효)
%   usesymmetry: 대칭면 사용 여부 (0=사용 안함, 1=사용)
%   symplanes  : 대칭면 정점 행렬 (usesymmetry=1일 때만 유효)
%
% 출력:
%   Sth        : [ip x it] theta 편파 RCS [dBsm]
%   Sph        : [ip x it] phi 편파 RCS [dBsm]
%   theta_out  : [ip x it] theta 각도 행렬 [deg]
%   phi_out    : [ip x it] phi 각도 행렬 [deg]
%   Ethscat    : [ip x it] theta 편파 산란 전기장 (복소수)
%   Ephscat    : [ip x it] phi 편파 산란 전기장 (복소수)
% =========================================================================

warning('off');

C = 3e8; % 광속 [m/s]

%% ── 기하 데이터 초기화 ──────────────────────────────────────────────────
nvert = size(coord, 1);
ntria = size(facet, 1);

%% ── ground plane: xy 대칭 모델 생성 ────────────────────────────────────
if useground == 1
    % 원본 보존
    coord_orig = coord;
    facet_orig = facet;
    matrl_orig = matrl;
    % xy 평면 대칭 모델 생성 (xysymmetric 함수 인라인)
    ncoord = size(coord, 1);
    coord_sym = coord;
    coord_sym(:, 3) = -coord_sym(:, 3);
    coord = [coord; coord_sym];
    facet_sym = facet;
    facet_sym(:, 2) = facet(:, 3);
    facet_sym(:, 3) = facet(:, 2);
    facet_sym(:, 1:3) = facet_sym(:, 1:3) + ncoord;
    facet = [facet; facet_sym];
    matrl = [matrl; matrl];
    nvert = size(coord, 1);
    ntria = size(facet, 1);
end

%% ── 파장 및 산란 파라미터 ───────────────────────────────────────────────
wave  = C / (freq * 1e9);          % 파장 [m]
bk    = 2 * pi / wave;             % 파수
corel = corr / wave;               % 정규화 상관 거리
delsq = std_dev^2;                 % 분산
cfac1 = exp(-4 * bk^2 * delsq);   % 정합 인자
cfac2 = 4 * pi * (bk * corel)^2 * delsq; % 확산 인자
rad   = pi / 180;

%% ── 각도 배열 크기 계산 ─────────────────────────────────────────────────
it = floor((tstop  - tstart) / delt) + 1;
ip = floor((pstop  - pstart) / delp) + 1;

%% ── 대칭면 전처리 ───────────────────────────────────────────────────────
if usesymmetry == 1
    symnumber = size(symplanes, 1) / 3;
    for i = 1:symnumber
        A = symplanes((i-1)*3+2, :) - symplanes((i-1)*3+1, :);
        B = symplanes((i-1)*3+3, :) - symplanes((i-1)*3+2, :);
        symN(i, :) = -cross(B, A);
        symNn = norm(symN(i, :));
        symN(i, :) = symN(i, :) / symNn;
        symbeta(i)  = acos(symN(i, 3));
        symalpha(i) = atan2(symN(i, 2), symN(i, 1));
        ca = cos(symalpha(i)); sa = sin(symalpha(i));
        cb = cos(symbeta(i));  sb = sin(symbeta(i));
        symT1{i} = [ca sa 0; -sa ca 0; 0 0 1];
        symT2{i} = [cb 0 -sb; 0 1 0; sb 0 cb];
    end
end

%% ── 입사 편파 설정 ──────────────────────────────────────────────────────
if i_pol == 1
    Et = 1 + 1j*0;
    Ep = 0 + 1j*0;
else
    Et = 0 + 1j*0;
    Ep = 1 + 1j*0;
end

%% ── 기하 전처리: 정점, 노말, 면적, 회전각 ──────────────────────────────
x = coord(:, 1);
y = coord(:, 2);
z = coord(:, 3);

node1 = facet(:, 1);
node2 = facet(:, 2);
node3 = facet(:, 3);
ilum  = facet(:, 4);  % 조명 플래그
Rs    = facet(:, 5);  % 표면 저항률

iflag = 0; % 조명 테스트 완전 비활성화 플래그 (0=정상 동작)

for i = 1:ntria
    vind(i, :) = [node1(i) node2(i) node3(i)];
end

for i = 1:nvert
    r(i, :) = [x(i) y(i) z(i)];
end

% 노말, 면적, 회전각 계산
for i = 1:ntria
    A_vec = r(vind(i,2), :) - r(vind(i,1), :);
    B_vec = r(vind(i,3), :) - r(vind(i,2), :);
    C_vec = r(vind(i,1), :) - r(vind(i,3), :);
    N_raw = -cross(B_vec, A_vec);
    d_len(i, 1) = norm(A_vec);
    d_len(i, 2) = norm(B_vec);
    d_len(i, 3) = norm(C_vec);
    ss = 0.5 * sum(d_len(i, :));
    Area(i) = sqrt(ss * (ss - d_len(i,1)) * (ss - d_len(i,2)) * (ss - d_len(i,3)));
    Nn = norm(N_raw);
    N(i, :) = N_raw / Nn;          % 단위 노말
    beta(i)  = acos(N(i, 3));     % 극각
    alpha(i) = atan2(N(i, 2), N(i, 1)); % 방위각
end

%% ── 메인 루프: phi x theta ──────────────────────────────────────────────
fprintf('Computing Monostatic RCS: freq=%.3f GHz, %d phi x %d theta points\n', freq, ip, it);

for i1 = 1:ip
    for i2 = 1:it

        phi(i1, i2)   = pstart + (i1-1) * delp;
        theta(i1, i2) = tstart + (i2-1) * delt;
        phr = phi(i1, i2)   * rad;
        thr = theta(i1, i2) * rad;

        % 방향 코사인
        st = sin(thr); ct = cos(thr);
        cp = cos(phr); sp = sin(phr);
        u = st*cp; v = st*sp; w = ct;
        D0 = [u v w];
        U(i1, i2) = u; V(i1, i2) = v; W(i1, i2) = w;

        alreadycomputed = 0;

        %── 대칭 처리 ────────────────────────────────────────────────────
        if usesymmetry == 1
            changed = 0;
            for i = 1:symnumber
                symD1  = symT1{i} * D0.';
                symuvw = symT2{i} * symD1;
                symtheta = acos(symuvw(3));
                if sin(symtheta) ~= 0
                    symphi = acos(symuvw(1) / sin(symtheta));
                end
                if symtheta > pi/2
                    changed = 1;
                    symtheta = abs(pi - symtheta);
                    if sin(symtheta) ~= 0
                        symuvw2 = [sin(symtheta)*cos(symphi);
                                   sin(symtheta)*sin(symphi);
                                   cos(symtheta)];
                    else
                        symuvw2 = [0; 0; 1];
                    end
                    DD1 = symT2{i}.' * symuvw2;
                    DD0 = symT1{i}.' * DD1;
                    thr = acos(DD0(3));
                    if sin(thr) ~= 0
                        phr = acos(DD0(1) / sin(thr));
                        st = sin(thr); ct = cos(thr);
                        cp = cos(phr); sp = sin(phr);
                        u = st*cp; v = st*sp; w = ct;
                    else
                        u = 0; v = 0; w = 1;
                    end
                    D0 = [u v w];
                end
            end
            if changed == 1
                phd = phr / rad;
                thd = thr / rad;
                if ~isempty(find(abs(phi - phd) <= 1e-3, 1))
                    pf = find(abs(phi - phd) <= 1e-3);
                    tf = find(abs(theta(pf) - thd) <= 1e-3);
                    if ~isempty(tf)
                        alreadycomputed = 1;
                        indexfound = pf(tf(1));
                    end
                end
            end
        end % usesymmetry

        %── 이미 계산된 각도면 복사 후 다음으로 ─────────────────────────
        if alreadycomputed == 1
            Sth(i1, i2) = Sth(indexfound);
            Sph(i1, i2) = Sph(indexfound);
            Ethscat(i1, i2) = Ethscat(indexfound);
            Ephscat(i1, i2) = Ephscat(indexfound);
            continue;
        end

        %── 입사장 (전역 직교 좌표) ──────────────────────────────────────
        uu = ct*cp; vv = ct*sp; ww = -st;
        e0_vec(1) = uu*Et - sp*Ep;
        e0_vec(2) = vv*Et + cp*Ep;
        e0_vec(3) = ww*Et;

        %── Ground plane 반사계수 ────────────────────────────────────────
        grreflpar  = 0;
        grreflperp = 0;
        if useground == 1
            if pec == 1
                grreflpar  = -1;
                grreflperp = -1;
            else
                [grreflpar, grreflperp, ~, ~] = ReflCoeff(1, 1, relpermit, 1, thr);
            end
        end

        %── 삼각형 루프 ──────────────────────────────────────────────────
        sumt  = 0; sump  = 0;
        sumdt = 0; sumdp = 0;
        RCpar  = 0; RCperp = 0;

        for m = 1:ntria
            if rsmethod == 2
                [RCpar, RCperp] = RClayers(thr, phr, m, alpha(m), beta(m), freq*1e9);
            end

            if useground == 0
                % Case 1: ground 없음
                Einc = e0_vec;
                [Ets, Etd, Eps, Epd] = facetRCS(thr, phr, thr, phr, ...
                    N(m,:), ilum(m), iflag, alpha(m), beta(m), Rs(m), Area(m), ...
                    x, y, z, vind(m,:), Einc, Nt, Lt, cfac2, corel, wave, ...
                    0, 0, 0, rsmethod, RCpar, RCperp);
                sumt  = sumt  + Ets;
                sump  = sump  + Eps;
                sumdt = sumdt + abs(Etd);
                sumdp = sumdp + abs(Epd);

            else
                % Case 2: ground plane 있음
                if m <= ntria/2
                    % 직접 입사 → 직접 산란
                    Einc = e0_vec;
                    [Ets, Etd, Eps, Epd] = facetRCS(thr, phr, thr, phr, ...
                        N(m,:), ilum(m), iflag, alpha(m), beta(m), Rs(m), Area(m), ...
                        x, y, z, vind(m,:), Einc, Nt, Lt, cfac2, corel, wave, ...
                        grreflpar, grreflperp, 0, rsmethod, RCpar, RCperp);
                else
                    % 지면반사 입사 → 지면반사 산란
                    Et1 = Et * grreflpar;
                    Ep1 = Ep * grreflperp;
                    ex(1) = uu*Et1 - sp*Ep1;
                    ex(2) = vv*Et1 + cp*Ep1;
                    ex(3) = ww*Et1;
                    Einc = ex;
                    [Ets, Etd, Eps, Epd] = facetRCS(thr, phr, thr, phr, ...
                        N(m,:), ilum(m), iflag, alpha(m), beta(m), Rs(m), Area(m), ...
                        x, y, z, vind(m,:), Einc, Nt, Lt, cfac2, corel, wave, ...
                        grreflpar, grreflperp, 1, rsmethod, RCpar, RCperp);
                end
                sumt  = sumt  + Ets;
                sump  = sump  + Eps;
                sumdt = sumdt + abs(Etd);
                sumdp = sumdp + abs(Epd);

                % pi-theta 방향 산란 기여
                if m <= ntria/2
                    Einc = e0_vec;
                    [Ets, Etd, Eps, Epd] = facetRCS(pi-thr, phr, thr, phr, ...
                        N(m,:), ilum(m), iflag, alpha(m), beta(m), Rs(m), Area(m), ...
                        x, y, z, vind(m,:), Einc, Nt, Lt, cfac2, corel, wave, ...
                        grreflpar, grreflperp, 1, rsmethod, RCpar, RCperp);
                else
                    Et1 = Et * grreflpar;
                    Ep1 = Ep * grreflperp;
                    ex(1) = uu*Et1 - sp*Ep1;
                    ex(2) = vv*Et1 + cp*Ep1;
                    ex(3) = ww*Et1;
                    Einc = ex;
                    [Ets, Etd, Eps, Epd] = facetRCS(pi-thr, phr, thr, phr, ...
                        N(m,:), ilum(m), iflag, alpha(m), beta(m), Rs(m), Area(m), ...
                        x, y, z, vind(m,:), Einc, Nt, Lt, cfac2, corel, wave, ...
                        grreflpar, grreflperp, 0, rsmethod, RCpar, RCperp);
                end
                sumt  = sumt  + Ets;
                sump  = sump  + Eps;
                sumdt = sumdt + abs(Etd);
                sumdp = sumdp + abs(Epd);
            end

        end % 삼각형 루프


        %── RCS [dBsm] 계산 ─────────────────────────────────────────────
        Ethscat(i1, i2) = sumt;
        Ephscat(i1, i2) = sump;
        Sth(i1, i2) = 10*log10(4*pi * cfac1 * ...
            (abs(sumt)^2 + sqrt(1 - cfac1^2) * sumdt) / wave^2 + 1e-10);
        Sph(i1, i2) = 10*log10(4*pi * cfac1 * ...
            (abs(sump)^2 + sqrt(1 - cfac1^2) * sumdp) / wave^2 + 1e-10);

        % 진행 상황 출력 (10% 단위)
        total = ip * it;
        done  = (i1-1)*it + i2;
        if mod(done, max(1, floor(total/10))) == 0
            fprintf('  %3d / %3d  (%.0f%%)\n', done, total, 100*done/total);
        end

    end % theta 루프
end % phi 루프

%% ── ground plane 사용 시 원본 데이터 복원 ──────────────────────────────
if useground == 1
    coord = coord_orig;
    facet = facet_orig;
    matrl = matrl_orig;
end

%% ── 출력 ────────────────────────────────────────────────────────────────
theta_out = theta;
phi_out   = phi;

fprintf('Done. RCS range: theta-pol [%.1f ~ %.1f dBsm], phi-pol [%.1f ~ %.1f dBsm]\n', ...
    min(Sth(:)), max(Sth(:)), min(Sph(:)), max(Sph(:)));

end % function
