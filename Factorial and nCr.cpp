constexpr long long mod = 1e9 + 7;
constexpr long long MOD = 998244353;

// Power under mod (a ^ b) % mod
int modpow(int a, int b, int m = mod) {
    a = a & m; 
    int ans = 1;
    while (b) {
        if (b & 1) { 
            ans = (ans * a) % m; 
        }
        b = b >> 1; 
        a = (a * a) % m;
    }
    return ans;
}
 
// Inverse Mod (1 / a) % mod
int modinv(int a, int m = mod) { 
    return modpow(a, m - 2); 
}

const int N = 2e5 + 7;
vector<int> fac;

void fact() {
    fac.resize(N);
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i < N; ++i) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
}

// nCr % m
int nCr(int n, int r, int m = mod) {
    if(n < r) {
        return 0;
    }
    if(r == 0) {
        return 1;
    }
    int num = (fac[n] * modinv(fac[r], m)) % m;
    int den = modinv(fac[n - r], m) % m;
    return (num * den) % m;
}