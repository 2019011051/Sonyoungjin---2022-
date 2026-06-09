function edges = extract_edges(coord, facet)
% =========================================================================
% extract_edges.m
% 삼각형 메시에서 경계 엣지(boundary edge) 추출
%
% 원리:
%   - 삼각형 2개가 공유하는 엣지 = 내부 엣지 (PTD 불필요)
%   - 삼각형 1개만 가진 엣지   = 경계 엣지 (PTD 대상)
%
% 입력:
%   coord : [nvert x 3]  정점 좌표 (x, y, z) [m]
%   facet : [ntria x 5]  패싯 [v1, v2, v3, ilum, Rs] (1-based 인덱스)
%
% 출력:
%   edges : [nedge x 1] struct 배열
%     .v1       : 엣지 시작 정점 인덱스 (1-based)
%     .v2       : 엣지 끝   정점 인덱스 (1-based)
%     .p1       : 엣지 시작 정점 좌표 [1x3]
%     .p2       : 엣지 끝   정점 좌표 [1x3]
%     .pmid     : 엣지 중점 좌표 [1x3]
%     .length   : 엣지 길이 [m]
%     .tangent  : 엣지 단위 접선벡터 t^ [1x3]
%     .tri_idx  : 이 엣지를 가진 삼각형 인덱스
%     .face_normal : 해당 삼각형의 단위 노말벡터 [1x3]
%     .wedge_n  : wedge 외각 Nπ (half-plane PEC = 2π, N=2)
% =========================================================================
 
ntria = size(facet, 1);
v_idx = facet(:, 1:3);  % [ntria x 3] 정점 인덱스
 
fprintf('경계 엣지 추출 중... (삼각형 수: %d)\n', ntria);
 
%% ── 모든 엣지 목록 생성 ─────────────────────────────────────────────────
% 각 삼각형의 3개 엣지: (v1,v2), (v2,v3), (v3,v1)
% 정렬해서 방향 무관하게 비교
 
all_edges = zeros(ntria*3, 3);  % [정렬된 v_min, 정렬된 v_max, 삼각형 인덱스]
 
for m = 1:ntria
    v = v_idx(m, :);
    e1 = sort([v(1) v(2)]);
    e2 = sort([v(2) v(3)]);
    e3 = sort([v(3) v(1)]);
    all_edges(3*(m-1)+1, :) = [e1, m];
    all_edges(3*(m-1)+2, :) = [e2, m];
    all_edges(3*(m-1)+3, :) = [e3, m];
end
 
%% ── 경계 엣지 찾기 ──────────────────────────────────────────────────────
% 정렬 후 인접 행 비교: 같은 엣지가 1번만 나오면 경계
edge_keys = all_edges(:, 1:2);
[sorted_keys, sort_idx] = sortrows(edge_keys);
sorted_tris = all_edges(sort_idx, 3);
 
% 인접 행이 같은지 비교
is_same_prev = [false; all(sorted_keys(2:end,:) == sorted_keys(1:end-1,:), 2)];
is_same_next = [all(sorted_keys(1:end-1,:) == sorted_keys(2:end,:), 2); false];
 
% 경계 엣지: 앞뒤 모두 다른 것
is_boundary = ~is_same_prev & ~is_same_next;
 
boundary_idx = find(is_boundary);
nedge = length(boundary_idx);
 
fprintf('  전체 엣지: %d  경계 엣지: %d  내부 엣지: %d\n', ...
    size(all_edges,1)/3*3, nedge, size(all_edges,1) - nedge*2);
 
%% ── 삼각형 노말 미리 계산 ───────────────────────────────────────────────
tri_normals = zeros(ntria, 3);
for m = 1:ntria
    p1 = coord(v_idx(m,1), :);
    p2 = coord(v_idx(m,2), :);
    p3 = coord(v_idx(m,3), :);
    A = p2 - p1;
    B = p3 - p2;
    N = -cross(B, A);   % PoFacets 방식
    nn = norm(N);
    if nn > 1e-12
        tri_normals(m, :) = N / nn;
    end
end
 
%% ── 경계 엣지 구조체 생성 ────────────────────────────────────────────────
edges(nedge) = struct('v1',0,'v2',0,'p1',[],'p2',[],'pmid',[],...
    'length',0,'tangent',[],'tri_idx',0,'face_normal',[],'wedge_n',2);
 
for i = 1:nedge
    bidx = boundary_idx(i);
    va = sorted_keys(bidx, 1);
    vb = sorted_keys(bidx, 2);
    tri = sorted_tris(bidx);
 
    p1 = coord(va, :);
    p2 = coord(vb, :);
    edge_vec = p2 - p1;
    elen = norm(edge_vec);
 
    edges(i).v1          = va;
    edges(i).v2          = vb;
    edges(i).p1          = p1;
    edges(i).p2          = p2;
    edges(i).pmid        = (p1 + p2) / 2;
    edges(i).length      = elen;
    edges(i).tangent     = edge_vec / max(elen, 1e-12);
    edges(i).tri_idx     = tri;
    edges(i).face_normal = tri_normals(tri, :);
    edges(i).wedge_n     = 2;  % PEC half-plane: Nπ = 2π
end
 
%% ── 요약 출력 ────────────────────────────────────────────────────────────
lengths = [edges.length];
fprintf('  엣지 길이: min=%.4f m, max=%.4f m, mean=%.4f m\n', ...
    min(lengths), max(lengths), mean(lengths));
fprintf('경계 엣지 추출 완료: %d개\n', nedge);
 
end