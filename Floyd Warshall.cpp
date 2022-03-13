//adj[u] = [v, cost]
//adj[v] = [u, cost]
//inf = 1e18
void floydWarshall(int n, vector <vector<int>> &dist, vector <pair<int, int>> &adj) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = inf;
        }
        dist[i][i] = 0; // i to i, dist = 0
    }
    for (int i = 0; i < n; ++i) {
        for (auto j: adj[i]) {
            dist[i][j.fi] = min(dist[i][j.fi], j.se);
        }
    }
    // Main Logic
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}