void dijkstra(int src, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[src] = 0;
    pq.push(mp(0, src));
    while (sz(pq)) {
        int dist_src_to_par = pq.top().fi;
        int par = pq.top().se;
        pq.pop();
        if (dist_src_to_par > dist[par]) {
            continue;
        }
        for (auto x: adj[par]) {
            int to_go = x.fi;
            int dist_par_to_x = x.se;
            if (dist[to_go] > dist_src_to_par + dist_par_to_x) {
                dist[to_go] = dist_src_to_par + dist_par_to_x;
                pq.push(mp(dist[to_go], to_go));
            }
        }
    }
}