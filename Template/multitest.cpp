#include "bits/stdc++.h" // template by Benq
using namespace std; // Debug template credit: Benq, ramchandra

using ll = long long;
using ld = long double;
using db = double;
using str = string;
using ull = unsigned ll;

using pi = pair<ll, ll>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using pld = pair<ld, ld>;

using vi = vector<ll>;
using vd = vector<db>;
using vl = vector<ll>;
using vld = vector<ld>;
using vs = vector<str>;
using vb = vector<bool>;
using vc = vector<char>;
using vpi = vector<pl>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvi = vector<vl>;
using vvl = vector<vl>;
using vvc = vector<vc>;

#define pb push_back
#define eb emplace_back
#define mp(a, b) make_pair(a, b)
#define f first
#define s second
#define si(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define rs resize
#define ins insert
#define nl "\n"
#define sor(a) sort(all(a))
#define int long long
#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; } )

#define rep(i, a, b) for(auto i = (a); i < (b); ++i)
#define rop(i, a) rep(i, 0, a)
#define per(i, a, b) for(auto i = (b) - 1; i >= (a); --i)
#define por(i, a) per(i, 0, a)
#define trav(i, a) for (auto& i: a)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> void uni(vector<T>& v) { sor(v); v.erase(unique(all(v)), end(v)); }
constexpr int cdiv(const ll& a, const ll& b) { return a / b + ((a ^ b) > 0 && a % b); } // (a / b) rounded up 
constexpr int fdiv(const ll& a, const ll& b) { return a / b - ((a ^ b) < 0 && a % b); } // (a / b) rounded down
int fstTrue(function<bool(int)> f, int lo, int hi) { for(hi++; lo < hi;) { int mid = fdiv((lo + hi), 2); f(mid) ? hi = mid : lo = mid + 1; } return lo; }
int lstTrue(function<bool(int)> f, int lo, int hi) { for(lo--; lo < hi;) { int mid = fdiv((lo + hi + 1), 2); f(mid) ? lo = mid : hi = mid - 1; } return lo; }
constexpr int power(ll a, ll b, ll c) { ll res = 1; a %= c; while(b > 0) { if(b & 1) res = res * a % c; a = a * a % c; b >>= 1; } return res; }
constexpr int power(ll a, ll b) { ll res = 1; while(b > 0) { if(b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
constexpr ull modmul(ull a, ull b, const ull mod) { ll ret = a * b - mod * (ull)((ld)a * b / mod); return ret + ((ret < 0) - (ret >= (ll)mod)) * mod; }
constexpr ull modpow(ull a, ull b, const ull mod) { if(b == 0) { return 1; } ull res = modpow(a, b / 2, mod); res = modmul(res, res, mod); return b & 1 ? modmul(res, a, mod) : res; }
constexpr bool prime(ull n) { if(n < 2 || n % 6 % 4 != 1) { return n - 2 < 2; } ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}, s = __builtin_ctzll(n - 1), d = n >> s; trav(i, A) { ull p = modpow(i, d, n), a = s; while(p != 1 && p != n - 1 && i % n && a--) { p = modmul(p, p, n); } if(p != n - 1 && a != s) { return false; } } return true; }
constexpr int pct(int x) { x = (x & 0x5555555555555555LL) + ((x >> 1) & 0x5555555555555555LL); x = (x & 0x3333333333333333LL) + ((x >> 2) & 0x3333333333333333LL); x = (x & 0x0F0F0F0F0F0F0F0FLL) + ((x >> 4) & 0x0F0F0F0F0F0F0F0FLL); return (x * 0x0101010101010101LL) >> 56; }
// uni: O(nlog(n)), cdiv: O(1), fdiv: O(1), fstTrue: O(log(hi - lo)), lstTrue: O(log(hi - lo)), gcd: O(log(min(a, b))), lcm: O(log(min(a, b))), power: O(log(b)), prime: O(sqrt(a)), pct: O(1)

// TO_STRING
#define ts to_string
string ts(char c) { return string(1, c); }
string ts(bool b) { return b ? "true" : "false"; }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
template<class A> string ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
string ts(vector<bool> v) { string res = "{"; for(int i = 0; i < si(v); i++) { res += char('0' + v[i]); } res += "}"; return res; }
template<size_t SZ> string ts(bitset<SZ> b) { string res = ""; for(int i = 0; i < (ll)SZ; i++) { res += char('0' + b[i]); } return res; }
template<class A, class B> string ts(pair<A, B> p) { return "(" + ts(p.f) + ", " + ts(p.s) + ")"; }
template<class T> string ts(T v) { bool fst = 1; string res = "{"; for(const auto& x: v) { if(!fst) { res += ", "; } fst = 0; res += ts(x); } res += "}"; return res; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) { cerr << ts(h); if(sizeof...(t)) { cerr << ", "; } DBG(t...); }
void EDBG(string names) { names = names; }
template<class H, class... T> void EDBG(string names, H h, T... t) { auto pos = names.find(','); auto first_name = names.substr(0, pos); auto rest = names.substr(pos + 1); while(rest.front() == ' ') { rest = rest.substr(1); } cerr << "[" << first_name << "]: [" << ts(h) << "]" << nl; EDBG(rest, t...); }

#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define edbg(...) EDBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#define edbg(...) 7
#endif

// FILE I/O
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(20); }
void setIO(string s = "") { unsyncIO(); if(si(s)) { setIn(s + ".in"); setOut(s + ".out"); } }

const int MX = 2e5 + 5;
const long long INF = 1e18;
const long long MOD = 1e9 + 7; // 998244353
const long double PI = acos((ld)-1);
const long double EPS = 1e-18;



void solve() {
	
}

int32_t main() {
	setIO();

	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}
