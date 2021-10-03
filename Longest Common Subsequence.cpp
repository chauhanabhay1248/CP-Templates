// LCS
vector<vector<int>> dp(1050, vector<int>(1050, 0)); // -1 for recursive, 0 for iterative

void lcs(string &a, string &b, int n, int m) {
//    if (dp[n][m] != -1) {
//        return dp[n][m];
//    }
//    if (n == 0 || m == 0) {
//        return dp[n][m] = 0;
//    }
//    if (a[n - 1] == b[m - 1]) {
//        return dp[n][m] = 1 + lcs(a, b, n - 1, m - 1);
//    } else {
//        return dp[n][m] = max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1));
//    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[n][m] << " ";
    vector<char> ans;
    int i = n;
    int j = m;
    while (i && j) {
        if (a[i - 1] == b[j - 1]) {
            ans.push_back(a[i-- - 1]);
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) {
        cout << x;
    }
}