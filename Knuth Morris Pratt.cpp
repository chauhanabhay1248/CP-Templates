vector<int> kmp(string s) {
    int n = sz(s);
    vector<int> lps(n);
    int l = 1;
    int len = 0;
    while (l < n) {
        if (s[l] == s[len]) {
            len++;
            lps[l++] = len;
        } else {
            if (len == 0) {
                lps[l++] = 0;
            } else {
                len = lps[len - 1];
            }
        }
    }
    return lps;
}

// inside main ->

int l = 0;
int r = 0;      // n = length of pattern, m = length of string to be search in pattern
while (l < n) {
    if (s[l] == p[r]) {
        l++;
        r++;
    }
    if (r == m) {
        cout << l - r << endl;
        r = lps[r - 1];
    } else if (l < n && s[l] != p[r]) {
        if (r == 0) {
            l++;
        } else {
            r = lps[r - 1];
        }
    }
}