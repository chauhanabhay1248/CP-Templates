/* Abhay Singh Chauhan */
// Sparse Table
struct item {
    int ac;
};

struct sparseTable {
    int sze;
    int mxlog;
    vector<int> logval;
    vector<vector<item>> table;

    item merge(item a, item b) { // min, max, gcd
        return {min(a.ac, b.ac)};
    }

    item single(int v) {
        return {v};
    }

    void build(vector<int> &a) {
        sze = a.size();
        mxlog = log2(sze);
        table.resize(sze + 1);
        logval.resize(sze + 1);

        logval[1] = 0;
        for (int i = 2; i <= sze; ++i) {
            logval[i] = logval[i / 2] + 1;
        }

        for (int i = 0; i < sze; ++i) {
            table[i].resize(mxlog + 1);
            fill(table[i].begin(), table[i].end(), item());
        }

        for (int i = 0; i < sze; i++) {
            table[i][0] = single(a[i]);
        }
        for (int i = 1; i <= mxlog; i++) {
            for (int j = 0; (j + (1 << i)) <= sze; j++) {
                table[j][i] = merge(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    item query(int l, int r) {
        int j = logval[r - l + 1];
        item ans = item();
        ans = merge(table[l][j], table[r - (1 << j) + 1][j]); // O(1)
        return ans;
    }
};