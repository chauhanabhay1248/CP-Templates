/* Abhay Singh Chauhan */
// Disjoint Set Union
struct DSU {
    vector<int> par;
    vector<int> sze;
    int connected; // stores number of connected components

    void init(int n) { // initialize DSU
        par.resize(n + 1);
        sze.assign(n + 1, 1);
        iota(all(par), 0);
        connected = n;
    }

    int get(int x) { // get parent
        return (par[x] = (par[x] == x ? x : get(par[x])));
    }

    int getSize(int u) { // get size of component
        return sze[get(u)];
    }

    void un(int x, int y) { // unite two components
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