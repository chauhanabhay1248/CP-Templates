// Segment Tree
struct item {
    int ac;
};

struct segtree {
    int sze;
    vector<item> values;

    item neutral = {0};

    item merge(item a, item b) {
        return {a.ac + b.ac};
    }

    item single(int v) {
        return {v};
    }

    void init(int n) {
        sze = 1;
        while (sze < n) {
            sze *= 2;
        }
        values.resize(2 * sze);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) {
                values[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void build(vector<int> &a) {
        build(a, 0, 0, sze);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            values[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, sze);
    }

    item query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) {
            return neutral;
        }
        if (lx >= l && rx <= r) {
            return values[x];
        }
        int m = (lx + rx) / 2;
        item s1 = query(l, r, x * 2 + 1, lx, m);
        item s2 = query(l, r, x * 2 + 2, m, rx);
        return merge(s1, s2);
    }

    item query(int l, int r) {
        return query(l, r, 0, 0, sze);
    }
};