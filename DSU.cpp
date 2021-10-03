struct DSU {
    vector<int> par;
    vector<int> sze;
    int connected;

    void init(int n) {
        par.resize(n + 1);
        sze.assign(n + 1, 1);
        iota(all(par), 0);
        connected = n;
    }

    int get(int x) {
        return (par[x] = (par[x] == x ? x : get(par[x])));
    }

    int getSize(int u) {
        return sze[get(u)];
    }

    void un(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return;
        }
        if (sze[x] > sze[y]) {
            swap(x, y);
        }
        sze[y] += sze[x];
        sze[x] = 0;
        par[x] = y;
        connected--;
    }
};