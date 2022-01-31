constexpr long long LOG = 20;
constexpr long long N = 1e4 + 5;
vector<vector<int>> up(N, vector<int>(LOG)); // up[v][i] is 2^i-th ancestor of v
vector<int> depth(N);

void dfs_lift(int u) {
    for(auto v: gr[u]) {
        depth[v] = depth[u] + 1; // depth of u
        up[v][0] = u; // u is parent of v
        for(int i = 1; i < LOG; i ++) {
            up[v][i] = up[up[v][i - 1]][i - 1]; // lifting
        }
        dfs_lift(v);
    }
}