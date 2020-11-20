#include "bits/stdc++.h" // template by Benq
using namespace std; // Debug template by neal

using ll = long long;
using ld = long double;
using db = double;
using str = string;
using ull = unsigned ll;

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
#define sor(a) sort(all(a))
#define int long long
#define trav(i, a) for(auto& i: a)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> void uni(vector<T>& v) { sor(v); v.erase(unique(all(v)), end(v)); }
constexpr int cdiv(const int& a, const int& b) { return a / b + ((a ^ b) > 0 && a % b); } // (a / b) rounded up 
constexpr int fdiv(const int& a, const int& b) { return a / b - ((a ^ b) < 0 && a % b); } // (a / b) rounded down
int power(int a, int b, int c) { int res = 1; a %= c; while(b > 0) { if(b & 1) res = res * a % c; a = a * a % c; b >>= 1; } return res; }
int power(int a, int b) { int res = 1; while(b > 0) { if(b & 1) res = res * a; a = a * a; b >>= 1; } return res; }

// INPUT
template <class T> istream& operator >> (istream& is, vector<T>& hld) { for(int i = 0; i < si(hld); ++i) { cin >> hld[i]; } return is; }
template <class T> istream& operator >> (istream& is, vector<vector<T>>& hld) { for(int i = 0; i < si(hld); ++i) { cin >> hld[i]; } return is; }
template <class T, class U> istream& operator >> (istream& is, pair<T, U>& hld) { is >> hld.first >> hld.second; return is; }

// DEBUG
template <class T, class H> ostream& operator << (ostream &os, const pair<T, H> &p) { return os << '(' << p.f << ", " << p.s << ')'; }
template <class T_container, class T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator << (ostream& os, const T_container& v) { os << '{'; string sep; for(const T& x: v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << "[" << H << "]"; if(sizeof...(T)) { cerr << ", "; } dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: ", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// FILE I/O
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10); }
void setIO(string s = "") { unsyncIO(); if(si(s)) { setIn(s + ".in"); setOut(s + ".out"); } }

const string nl = "\n";
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; // 998244353
const ld PI = acos((ld)-1);
const ld EPS = 1e-8;



int32_t main() {
	setIO();

	
}
