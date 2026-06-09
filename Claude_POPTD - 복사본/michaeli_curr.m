function [I_eq, M_eq] = michaeli_curr(s_hat, s_hat_inc, t_hat, n_hat, k, E_inc, H_inc)
% =========================================================================
% michaeli_curr.m
% Michaeli (1984) 등가 엣지 전류 계산
% "Equivalent Edge Currents for Arbitrary Aspects of Observation"
% IEEE TAP, Vol. AP-32, No.3, March 1984
%
% PEC half-plane (N=2), backscattering (beta = pi - beta') 케이스
% 논문 식 (38) 구현
%
% 입력:
%   s_hat     : 관측방향 단위벡터 [1x3]
%   s_hat_inc : 입사방향 단위벡터 [1x3] (monostatic: s_hat = -s_hat_inc 아님!)
%               주의: PoFacets 관례에서 s_hat_inc는 소스→표면 방향
%   t_hat     : 엣지 접선 단위벡터 [1x3]
%   n_hat     : upper face 외부 노말 단위벡터 [1x3]
%   k         : 파수 [rad/m]
%   E_inc     : 입사 전기장 벡터 [1x3] (복소수)
%   H_inc     : 입사 자기장 벡터 [1x3] (복소수)
%
% 출력:
%   I_eq : 등가 전기 전류 (복소 스칼라) [A]
%   M_eq : 등가 자기 전류 (복소 스칼라) [V]
%
% 좌표계 (논문 Fig.1):
%   t_hat : 엣지 방향 (z축)
%   n_hat : upper face 외부 노말 (y축)
%   x_hat : upper face 법선 방향 = n_hat × t_hat 의 반대 (x축)
% =========================================================================

Z0 = 120 * pi;   % 자유공간 임피던스 [Ω]
Y0 = 1 / Z0;

%% ── 엣지 고정 좌표계 설정 ─────────────────────────────────────────────
% 논문 Fig.1: x축은 upper face 위에서 엣지에 수직
% x_hat = t_hat × n_hat (right-hand: t=z, n=y -> x=z×y = -x_global 이 될 수도)
x_hat = cross(t_hat, n_hat);
x_hat = x_hat / (norm(x_hat) + 1e-12);

%% ── beta' 계산 (입사방향과 엣지 사이 각도) ────────────────────────────
cos_beta_p = dot(s_hat_inc, t_hat);
cos_beta_p = max(min(cos_beta_p, 1), -1);
beta_p     = acos(cos_beta_p);
sin_beta_p = sin(beta_p);

% sin_beta_p가 너무 작으면 (엣지에 평행 입사) → 기여 무시
if sin_beta_p < 1e-6
    I_eq = 0;
    M_eq = 0;
    return;
end

%% ── phi' 계산 (입사 방향의 엣지 고정 방위각) ─────────────────────────
% 입사방향을 엣지 수직 평면에 투영
s_perp_inc = s_hat_inc - cos_beta_p * t_hat;
s_perp_norm = norm(s_perp_inc);

if s_perp_norm < 1e-6
    I_eq = 0;
    M_eq = 0;
    return;
end
s_perp_inc = s_perp_inc / s_perp_norm;

% phi' = 입사 수직 성분과 x_hat 사이 각도
cos_phi_p = dot(s_perp_inc, x_hat);
cos_phi_p = max(min(cos_phi_p, 1), -1);

% y_hat 방향 성분으로 부호 결정
sin_phi_p = dot(s_perp_inc, n_hat);
phi_p = atan2(sin_phi_p, cos_phi_p);

%% ── backscattering: phi = phi' ────────────────────────────────────────
phi_obs     = phi_p;
cos_phi_obs = cos(phi_obs);
sin_phi_obs = sin(phi_obs);

% cos_phi_obs = 0 (grazing) 특이점 처리
if abs(cos_phi_obs) < 1e-6
    cos_phi_obs = 1e-6 * sign(cos_phi_obs + 1e-12);
end
if abs(sin_phi_obs) < 1e-6
    sin_phi_obs = 1e-6 * sign(sin_phi_obs + 1e-12);
end

%% ── 입사장 z성분 추출 ─────────────────────────────────────────────────
% 논문: E_z0, H_z0 = 엣지 방향(t_hat) 성분
E_z0 = dot(E_inc, t_hat);
H_z0 = dot(H_inc, t_hat);

%% ── 식 (38) M_back, I_back 계산 ──────────────────────────────────────
% M_back = H_z0 * Z0*(1 + cos_phi) / (jk * sin^2(beta') * cos_phi)
M_eq = H_z0 * Z0 * (1 + cos_phi_obs) / ...
       (1j * k * sin_beta_p^2 * cos_phi_obs);

% I_back = E_z0 * Y0*(cos_phi - 1) / (jk * sin^2(beta') * cos_phi)
%        - H_z0 * 2*cos(beta')*(1+cos_phi) / (jk * sin^2(beta') * sin_phi)
I_eq = E_z0 * Y0 * (cos_phi_obs - 1) / ...
       (1j * k * sin_beta_p^2 * cos_phi_obs) ...
     - H_z0 * 2 * cos(beta_p) * (1 + cos_phi_obs) / ...
       (1j * k * sin_beta_p^2 * sin_phi_obs);

end