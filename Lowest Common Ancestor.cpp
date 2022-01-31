int lca(int u, int v) { // lowest common ancestor
    if(depth[u] < depth[v]) { // to store more deeper in u to lift up
        swap(u, v);
    }
    int k = depth[u] - depth[v]; // how much to lift
    for(int i = LOG - 1; i >= 0; i --) {
        if((k >> i) & 1ll) {
            u = up[u][i];
        }
    }
    if(u == v) { //if u == v then u or v are ancestors rn
        return u;
    }
    for(int i = LOG - 1; i >= 0; i --) { // lifting u and v up if their ancestors are not same
        if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0]; // lca will the parent of u or v
}