int powermod(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % mod;
        }
        b = b >> 1;
        a = (a * a) % mod;
    }
    return ans;
}