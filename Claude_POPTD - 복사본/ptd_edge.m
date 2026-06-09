function [Eth_fringe, Eph_fringe] = ptd_edge(edges, s_hat, s_hat_inc, ...
    k, wave, E_inc_vec, i_pol, thr, phr)
% =========================================================================
% ptd_edge.m
% 경계/날카로운 엣지에 대한 PTD fringe field 계산
% Michaeli (1984) 등가전류 기반 엣지 선적분
%
% 입력:
%   edges      : extract_edges.m 출력 구조체 배열
%   s_hat      : 관측방향 단위벡터 [1x3] (monostatic: = 입사방향)
%   s_hat_inc  : 입사방향 단위벡터 [1x3]
%   k          : 파수 [rad/m]
%   wave       : 파장 [m]
%   E_inc_vec  : 입사 전기장 벡터 [1x3] (단위 진폭, 복소수)
%   i_pol      : 편파 (1=theta, 2=phi)
%   thr        : theta 관측각 [rad]
%   phr        : phi 관측각 [rad]
%
% 출력:
%   Eth_fringe : theta 편파 fringe 산란장 (복소 스칼라)
%   Eph_fringe : phi 편파 fringe 산란장 (복소 스칼라)
% =========================================================================
 
Z0 = 120 * pi;
Y0 = 1 / Z0;
 
Eth_fringe = 0;
Eph_fringe = 0;
 
nedge = length(edges);
if nedge == 0
    return;
end
 
%% ── 관측방향 단위벡터 ─────────────────────────────────────────────────
st = sin(thr); ct = cos(thr);
cp = cos(phr); sp = sin(phr);
 
% theta, phi 방향 단위벡터 (구면좌표)
e_theta = [ct*cp, ct*sp, -st];
e_phi   = [-sp,   cp,    0  ];
 
%% ── 입사 자기장 계산 ──────────────────────────────────────────────────
% H_inc = (1/Z0) * k_hat × E_inc
% 입사방향: -s_hat_inc (소스→표면)
k_hat = -s_hat_inc;  % 파 진행 방향
H_inc_vec = (1/Z0) * cross(k_hat, E_inc_vec);
 
%% ── 엣지 루프 ────────────────────────────────────────────────────────
for i = 1:nedge
    p1     = edges(i).p1;
    p2     = edges(i).p2;
    t_hat  = edges(i).tangent;
    n_hat  = edges(i).face_normal;
    elen   = edges(i).length;
 
    if elen < 1e-10
        continue;
    end
 
    %── 엣지를 N_seg 개 세그먼트로 나눠서 적분 ──────────────────────────
    % 엣지 길이가 lambda/4 이하면 1개, 아니면 lambda/4 간격
    N_seg = max(1, round(elen / (wave / 4)));
    N_seg = min(N_seg, 20);  % 최대 20개 세그먼트
 
    dl = elen / N_seg;  % 세그먼트 길이
 
    for n = 1:N_seg
        % 세그먼트 중점
        t_param = ((n - 0.5) / N_seg);
        r_seg = p1 + t_param * (p2 - p1);
 
        % 위상 항: exp(jk*(s_hat_inc + s_hat) . r)
        % monostatic: s_hat = s_hat_inc 방향에서 반사
        phase = k * dot(s_hat_inc + s_hat, r_seg);
        phase_factor = exp(1j * phase);
 
        %── Michaeli 등가전류 계산 ─────────────────────────────────────
        [I_eq, M_eq] = michaeli_curr(s_hat, s_hat_inc, t_hat, n_hat, ...
            k, E_inc_vec, H_inc_vec);
 
        %── 복사 적분: MEC 공식 ───────────────────────────────────────
        % E^d = -jk * [Z*I*(s×(s×t)) + M*(s×t)] * exp(jk*s.r) * dl
        % 여기서 s = 관측방향 s_hat
        s = s_hat;
 
        % Z*I 기여: s × (s × t_hat)
        sxt   = cross(s, t_hat);
        sxsxt = cross(s, sxt);
        E_I   = Z0 * I_eq * sxsxt;
 
        % M 기여: s × t_hat
        E_M   = M_eq * sxt;
 
        % 총 전기장 기여
        dE = -1j * k * (E_I + E_M) * phase_factor * dl;
 
        % theta, phi 성분 투영
        Eth_fringe = Eth_fringe + dot(dE, e_theta);
        Eph_fringe = Eph_fringe + dot(dE, e_phi);
    end
end
 
end