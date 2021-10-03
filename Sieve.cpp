int N = 1e7 + 7;
vector<int> pr;
//vector<int> fcnt;
vector<bool> prime;
vector<int> spf;

void sieve() {
    prime.assign(N, true);
    spf.resize(N);
//    fcnt.resize(N);

    prime[1] = false;
    for (int p = 2; p < N; p++) {
        if (prime[p]) {
            spf[p] = p;
            for (int i = p + p; i <= N; i += p) {
                prime[i] = false; // not prime
                if(spf[i] == 0) {
                    spf[i] = p; // first divisor of i
                }
            }
        }
    }

    for (int p = 2; p <= N; p++) { // storing primes
        if (prime[p]) {
            pr.pb(p);
        }
    }
//
//    for (int i = 2; i < N; ++i) { // counting factors of i
//        fcnt[i] = fcnt[i / spf[i]] + 1;
//    }
//
//    for (int i = 1; i < N; ++i) {
//        fcnt[i] += fcnt[i - 1];
//    }
}