function [coord, facet] = stl2mat(stl_file, out_mat, unit_scale)
% =========================================================================
% stl2mat.m
% STL 파일 → PoFacets 호환 MAT 파일 변환
%
% 사용법:
%   stl2mat('reaper.stl')                % 기본값 (단위 그대로, mat 자동 저장)
%   stl2mat('reaper.stl', 'reaper.mat')  % 출력 파일명 지정
%   stl2mat('reaper.stl', 'reaper.mat', 0.001)  % mm → m 변환 (×0.001)
%
% 입력:
%   stl_file   : STL 파일 경로 (ASCII or Binary 자동 감지)
%   out_mat    : 출력 MAT 파일명 (기본: stl 파일명 + .mat)
%   unit_scale : 단위 변환 계수 (기본: 1.0)
%                  mm → m : 0.001
%                  cm → m : 0.01
%                  inch→m : 0.0254
%
% 출력 MAT 변수:
%   coord : [nvert x 3]  정점 좌표 (x, y, z) [m] (중복 제거됨)
%   facet : [ntria x 5]  패싯 [v1, v2, v3, ilum_flag, Rs]
%             ilum_flag = 0 (양면 조명, PEC 기본값)
%             Rs        = 0 (PEC)
% =========================================================================

%% ── 인자 기본값 처리 ────────────────────────────────────────────────────
if nargin < 2 || isempty(out_mat)
    [fpath, fname, ~] = fileparts(stl_file);
    out_mat = fullfile(fpath, [fname '.mat']);
end
if nargin < 3 || isempty(unit_scale)
    unit_scale = 1.0;
end

fprintf('STL 파일 읽는 중: %s\n', stl_file);

%% ── ASCII / Binary 자동 감지 ────────────────────────────────────────────
fid = fopen(stl_file, 'rb');
if fid < 0
    error('파일을 열 수 없습니다: %s', stl_file);
end
header = fread(fid, 80, 'uint8=>char')';
fclose(fid);

is_ascii = strncmpi(strtrim(header), 'solid', 5);

% Binary STL도 "solid"로 시작할 수 있음 → 파일 크기로 재확인
if is_ascii
    finfo = dir(stl_file);
    fid = fopen(stl_file, 'rb');
    fread(fid, 80, 'uint8');         % 헤더 skip
    ntria_bin = fread(fid, 1, 'uint32');
    fclose(fid);
    expected_size = 84 + ntria_bin * 50;
    if abs(finfo.bytes - expected_size) < 10
        is_ascii = false;            % 실제로 Binary
    end
end

%% ── STL 읽기 ────────────────────────────────────────────────────────────
if is_ascii
    fprintf('  포맷: ASCII STL\n');
    [verts_raw, normals_raw] = read_ascii_stl(stl_file);
else
    fprintf('  포맷: Binary STL\n');
    [verts_raw, normals_raw] = read_binary_stl(stl_file);
end

ntria_raw = size(verts_raw, 1) / 3;
fprintf('  원시 삼각형 수: %d\n', ntria_raw);

%% ── 단위 변환 ───────────────────────────────────────────────────────────
verts_raw = verts_raw * unit_scale;

%% ── 중복 정점 제거 (unique) ─────────────────────────────────────────────
% 허용 오차: 모델 크기의 1e-6 수준
tol = max(range(verts_raw)) * 1e-6;
tol = max(tol, 1e-10);

% 정점을 반올림해서 unique 처리
scale_factor = 1 / tol;
verts_rounded = round(verts_raw * scale_factor);
[coord_int, ~, ic] = unique(verts_rounded, 'rows', 'stable');
coord = coord_int / scale_factor;

nvert = size(coord, 1);
ntria = ntria_raw;

fprintf('  중복 제거 후 정점 수: %d\n', nvert);
fprintf('  삼각형 수: %d\n', ntria);

%% ── facet 행렬 생성 ─────────────────────────────────────────────────────
% ic: [3*ntria x 1] → 각 삼각형의 3 정점 인덱스 (1-based)
v_idx = reshape(ic, 3, ntria)';  % [ntria x 3]

% PoFacets: [v1, v2, v3, ilum_flag, Rs]
% ilum_flag = 0 (양면 조명)
% Rs        = 0 (PEC)
facet = [v_idx, zeros(ntria, 2)];

%% ── 노말 방향 확인 ──────────────────────────────────────────────────────
% STL 노말과 right-hand rule 노말 비교 (첫 삼각형)
v1 = coord(facet(1,1), :);
v2 = coord(facet(1,2), :);
v3 = coord(facet(1,3), :);
A_vec = v2 - v1;
B_vec = v3 - v2;
N_rh  = cross(A_vec, B_vec);   % right-hand rule
N_rh  = N_rh / norm(N_rh);

% PoFacets 방식: N = -cross(B,A)
N_pof = -cross(B_vec, A_vec);
N_pof = N_pof / norm(N_pof);

stl_normal = normals_raw(1, :);
if norm(stl_normal) > 0
    stl_normal = stl_normal / norm(stl_normal);
    dot_check = dot(N_pof, stl_normal);
    if dot_check < -0.5
        fprintf('  경고: 노말 방향이 STL과 반대 → v2, v3 순서 교환\n');
        facet(:, [2,3]) = facet(:, [3,2]);
    else
        fprintf('  노말 방향: OK (STL과 일치)\n');
    end
end

%% ── 기하 정보 출력 ──────────────────────────────────────────────────────
fprintf('\n=== 기하 정보 ===\n');
fprintf('  x: %.4f ~ %.4f m\n', min(coord(:,1)), max(coord(:,1)));
fprintf('  y: %.4f ~ %.4f m\n', min(coord(:,2)), max(coord(:,2)));
fprintf('  z: %.4f ~ %.4f m\n', min(coord(:,3)), max(coord(:,3)));
fprintf('  크기: %.4f x %.4f x %.4f m\n', ...
    range(coord(:,1)), range(coord(:,2)), range(coord(:,3)));
fprintf('  정점: %d  삼각형: %d\n', nvert, ntria);

%% ── MAT 저장 ────────────────────────────────────────────────────────────
save(out_mat, 'coord', 'facet');
fprintf('\n저장 완료: %s\n', out_mat);
fprintf('  coord: [%d x 3]\n', size(coord,1));
fprintf('  facet: [%d x 5]  (col5=Rs=0, PEC)\n', size(facet,1));

end

%% ════════════════════════════════════════════════════════════════════════
%  내부 함수: ASCII STL 읽기
% ════════════════════════════════════════════════════════════════════════
function [verts, normals] = read_ascii_stl(fname)
    fid = fopen(fname, 'r');
    verts   = [];
    normals = [];
    while ~feof(fid)
        line = strtrim(fgetl(fid));
        if strncmpi(line, 'facet normal', 12)
            n = sscanf(line(13:end), '%f %f %f')';
            normals = [normals; n];
            fgetl(fid);  % outer loop
            v = zeros(3,3);
            for i = 1:3
                vline = strtrim(fgetl(fid));
                v(i,:) = sscanf(vline(7:end), '%f %f %f')';
            end
            verts = [verts; v];
        end
    end
    fclose(fid);
end

%% ════════════════════════════════════════════════════════════════════════
%  내부 함수: Binary STL 읽기
% ════════════════════════════════════════════════════════════════════════
function [verts, normals] = read_binary_stl(fname)
    fid = fopen(fname, 'rb');
    fread(fid, 80, 'uint8');          % 헤더 skip
    ntria = fread(fid, 1, 'uint32');  % 삼각형 수
    data  = fread(fid, ntria * 12 + ntria, 'float32=>float32');
    fclose(fid);

    % 각 삼각형: [nx ny nz  v1x v1y v1z  v2x v2y v2z  v3x v3y v3z  attr(2byte)]
    % float32로 읽으면 attr(2byte)가 float 하나에 포함됨 → 13 float/triangle
    data = reshape(data, 13, ntria)';
    normals = double(data(:, 1:3));
    v1 = double(data(:, 4:6));
    v2 = double(data(:, 7:9));
    v3 = double(data(:, 10:12));
    verts = zeros(ntria*3, 3);
    verts(1:3:end, :) = v1;
    verts(2:3:end, :) = v2;
    verts(3:3:end, :) = v3;
end