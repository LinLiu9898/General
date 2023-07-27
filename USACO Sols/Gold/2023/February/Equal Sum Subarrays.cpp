#include "bits/stdc++.h"
using namespace std;

#define int int64_t
#define trav(i, a) for(auto& i: a)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define si(a) ((int)(a).size())
#define ins insert
#define pb push_back
#define f first
#define s second

const int MOD = 1e9 + 7;
const int INF = 1e18;
const string nl = "\n";



int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	trav(i, a) {
		cin >> i;
	}
	vector<int> pref = a;
	for(int i = 1; i < n; ++i) {
		pref[i] += pref[i - 1];
	}
	auto get = [&](int l, int r) -> int {
		return pref[r] - (l == 0 ? 0 : pref[l - 1]);
	};
	vector<array<int, 3>> hld;
	for(int i = 0; i < n; ++i) {
		for(int j = i; j < n; ++j) {
			hld.pb({get(i, j), i, j});
		}
	}
	auto contains = [&](pair<int, int> x, int y) -> bool {
		return (x.f <= y && y <= x.s);
	};
	sort(all(hld));
	for(int i = 0; i < n; ++i) {
		int ans = INF;
		for(int j = 1; j < si(hld); ++j) {
			pair<int, int> x = make_pair(hld[j - 1][1], hld[j - 1][2]);
			pair<int, int> y = make_pair(hld[j][1], hld[j][2]);
			if(contains(x, i) != contains(y, i)) {
				ans = min(ans, hld[j][0] - hld[j - 1][0]);
			}
		}
		cout << ans << nl;
	}
}
