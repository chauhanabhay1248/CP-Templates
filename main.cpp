/* Abhay Singh Chauhan */
#include "bits/stdc++.h"

using namespace std;

// GCC Optimizations
#pragma GCC diagnostic ignored "-Wunused-variable" // Ignore unused variable warning
#pragma GCC diagnostic ignored "-Wunknown-pragmas" // Ignore unknown pragmas warning
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

// Macros
#define int long long
#define ll long long
#define ld long double

// Constants
constexpr long long SZ = 1e5 + 7;
constexpr long long inf = 1e18;
constexpr long long mod = 1e9 + 7;
constexpr long long MOD = 998244353;
constexpr long double PI = 3.141592653589793238462;

// Macros
#define vt vector // not cool
#define pb push_back
#define all(X) (X).begin(), (X).end()
#define allr(X) (X).rbegin(), (X).rend()
#define sz(X) (int)X.size()

#define each(x, a) for (auto &x: a)
#define forn(i, n) for (int i = 0; i < n; ++i)
#define forr(i, n) for (int i = n; i >=0; --i)

#define fi first
#define se second
#define Endl '\n'

#define setbits(X) __builtin_popcountll(X)
#define fix(X) fixed << setprecision(X)
#define mem0(X) memset((X), 0, sizeof((X)))
#define mem1(X) memset((X), -1, sizeof((X)))

// Debug Functions
void __print(int x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << x; }
void __print(const char *x) { cerr << x; }
void __print(const string &x) { cerr << x; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) {cerr << (f++ ? ", " : ""); __print(i);} cerr << "}";}
void _print() {cerr << "]\n";}
template<typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) {cerr << ", ";} _print(v...);}

#ifdef ambarsariya
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define  dbg(x...)
#endif

// Min Max
template<class T>
bool amin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T>
bool amax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

// Operator overloads <<, >>
template<typename T1, typename T2> // cin >> pair
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector
istream &operator>>(istream &istream, vector<T> &v) { for (auto &it : v) { cin >> it; } return istream; }
template<typename T1, typename T2> // cout << pair
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector
ostream &operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) { cout << it << " "; } return ostream; }

// Google
int tc_cnt = 1;
#define ns()               cout << "Case #" << tc_cnt ++ << ": ";

// Power under mod (a ^ b) % mod
int modpow(int a, int b, int m = mod) {
    a = a & m; int ans = 1;
    while (b) {
        if (b & 1) { ans = (ans * a) % m; }
        b = b >> 1; a = (a * a) % m;
    }
    return ans;
}

// Inverse Mod (1 / a) % mod
int modinv(int a, int m = mod) { return modpow(a, m - 2); }

// Modular Arithematic
int modadd(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
int modsub(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
int modmul(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
int moddiv(int a, int b, int m = mod) { a = a % m; b = b % m; return (modmul(a, modinv(b, m), m) + m) % m; }

// GCD
int gcd(int a, int b) { if (b == 0) { return a; } return gcd(b, a % b); }

// LCM
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

// Directions
const int dx[8] = {0, 1, -1, 0, -1, -1, 1, 1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};

void twoseven() {
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

// #ifdef ambarsariya
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int t = 1;
    cin >> t;
    while (t--) twoseven();
    return 0;
}

/* Thanking Almighty !! The Intellectual Odyssey Rages On */