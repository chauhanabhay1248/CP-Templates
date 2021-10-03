//Segmented Sieve [add sieve above]
void segSieve(int l, int r) {
    vector<bool> mrk(r - l + 1, true);
    for (auto x: pr) {
        int firstMul = (l / x) * x;
        if (firstMul < l) {
            firstMul += x;
        }
        for (int i = max(x * x, firstMul); i <= r; i += x) {
            mrk[i - l] = false;
        }
    }
    for (int i = max(2ll, l); i <= r; ++i) {
        if (mrk[i - l] == true) {
            cout << i << endl;
        }
    }
}