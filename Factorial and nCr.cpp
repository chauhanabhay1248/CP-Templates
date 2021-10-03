const int N = 2e5 + 7;

vector<int> fact;
vector<int> invfact;
vector<int> inv;

// Number Inverse
void numInv() {
    inv.resize(N);
    inv[0] = 1;
    inv[1] = 1;
    for (int i = 2; i < N; ++i) {
        inv[i] = mod - (inv[mod % i] * (mod / i) % mod);
    }
}

// Factorial Inverse
void factInv() {
    invfact.resize(N);
    invfact[0] = 1;
    invfact[1] = 1;
    for (int i = 2; i < N; ++i) {
        invfact[i] = (inv[i] * invfact[i - 1]) % mod;
    }
}

// Factorial
void fact() {
    fact.resize(N);
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < N; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

// nCr [n! / (r! * (n - r)!)]
int nCr(int n, int r) {
    if (r > n) {
        return 0;
    }
    return (((fact[n] * invfact[r]) % mod) * invfact[n - r]) % mod;
}