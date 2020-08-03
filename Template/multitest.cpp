#include "bits/stdc++.h" // template by Benq
using namespace std; // Debug template credit: Benq, ramchandra

using ll = long long;
using ld = long double;
using db = double;
using str = string;
using ull = unsigned ll;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using pld = pair<ld, ld>;

using vi = vector<int>;
using vd = vector<db>;
using vld = vector<ld>;
using vl = vector<ll>;
using vs = vector<str>;
using vc = vector<char>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvc = vector<vc>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define si(a) ((int)(a).size())
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define rs resize
#define ins insert
#define nl "\n"
#define tolower(a) transform(all(a), a.begin(), ::tolower)
#define toupper(a) transform(all(a), a.begin(), ::toupper)
#define gcd(a, b) ggcd(a, b)
#define lcm(a, b) llcm(a, b)

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(i, a) for (auto& i: a)

const int MX = 2e5 + 5;
const long long INF = 1e18;
const long long MOD = 998244353;
const long double PI = acos((ld)-1);
const long double EPS = 1e-18;

// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A, B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A, SZ>& a);
 
template<class T> void re(T& x) { cin >> x; }
void re(db& d) { string t; re(t); d = stod(t); }
void re(ld& d) { string t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
 
template<class A> void re(complex<A>& c) { A a, b; re(a, b); c = {a, b}; }
template<class A, class B> void re(pair<A, B>& p) { re(p.f, p.s); }
template<class A> void re(vector<A>& x) { trav(i, x) re(i); }
template<class A, size_t SZ> void re(array<A, SZ>& x) { trav(i, x) re(i); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }

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
#define chk(...) if(!(__VA_ARGS__)) cerr << "In function " << "(" << __FUNCTION__ << "), " << "CHK FAILED: (" << #__VA_ARGS__ << ")" << nl, exit(0);
#else
#define dbg(...) 42
#define edbg(...) 7
#define chk(...) 0
#endif

// OUTPUT
void pr() {}
template<class H, class... T> void pr(const H& a, const T&... b) { cout << a; pr(b...); }
void ps() { cout << nl; }
template<class H, class...T> void ps(const H& a, const T&... b) { pr(a, ' '); ps(b...); }

// FILE I/O
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(20), cerr << fixed << setprecision(20); }
void setIO(string s = "") { unsyncIO(); if(si(s)) { setIn(s + ".in"); setOut(s + ".out"); } }

template<class T> void uni(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)), end(v)); }
ll cdiv(const ll& a, const ll& b) { return a / b + ((a ^ b) > 0 && a % b); } // (a / b) rounded up 
ll fdiv(const ll& a, const ll& b) { return a / b - ((a ^ b) < 0 && a % b); } // (a / b) rounded down
bool even(const ll& a) { return !(a & 1); }
bool odd(const ll& a) { return (a & 1); }
ll ggcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }
ll gld(const ll& a, const ll& b) { return (a - (a % b)); } // returns the greatest number less than or equal to a and divides b evenly
ll llcm(const ll& a, const ll& b) { return (a / (ggcd(a, b)) * b); }
ll power(ll a, ll b, ll c) { ll res = 1; a %= c; while(b > 0) { if(odd(b)) res = res * a % c; a = a * a % c; b >>= 1; } return res; }
ll power(ll a, ll b) { ll res = 1; while(b > 0) { if(odd(b)) res = res * a; a = a * a; b >>= 1; } return res; }
ull modMul(ull a, ull b, const ull mod) { ll ret = a * b - mod * (ull)((ld)a * b / mod); return ret + ((ret < 0) - (ret >= (ll)mod)) * mod; }
ull modPow(ull a, ull b, const ull mod) { if(b == 0) { return 1; } ull res = modPow(a, b / 2, mod); res = modMul(res, res, mod); return b & 1 ? modMul(res, a, mod) : res; }
bool prime(ull n) { if(n < 2 || n % 6 % 4 != 1) { return n - 2 < 2; } ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}, s = __builtin_ctzll(n - 1), d = n >> s; trav(i, A) { ull p = modPow(i, d, n), a = s; while(p != 1 && p != n - 1 && i % n && a--) { p = modMul(p, p, n); } if(p != n - 1 && a != s) { return false; } } return true; }
ll C(ll n, ll k) { ll ans = 1; for(ll i = 1; i <= k; ++i) { ans = ans * (n - i + 1) / i; } return ans; }
ll pct(ll x) { x = (x & 0x5555555555555555LL) + ((x >> 1) & 0x5555555555555555LL); x = (x & 0x3333333333333333LL) + ((x >> 2) & 0x3333333333333333LL); x = (x & 0x0F0F0F0F0F0F0F0FLL) + ((x >> 4) & 0x0F0F0F0F0F0F0F0FLL); return (x * 0x0101010101010101LL) >> 56; }
// uni: O(nlog(n)), cdiv: O(1), even: O(1), odd: O(1), gcd: O(log(min(a, b))), gld: O(1), lcm: O(log(min(a, b))), power: O(log(b)), prime: O(sqrt(a)), C: O(k)



void solve() {
	
}


int main() {
	setIO();

	int T;
	re(T);
	while(T--) {
		solve();
	}
}
