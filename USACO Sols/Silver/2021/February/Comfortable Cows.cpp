#include "bits/stdc++.h"
using namespace std;

#define int int64_t
#define trav(i, a) for(auto& i: a)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define si(a) ((int)(a).size())
#define ins insert
#define pb push_back
#define mp make_pair
#define f first
#define s second

const int MOD = 1e9 + 7;
const int INF = 1e18;
const string nl = "\n";

const vector<int> dx = {0, -1, 0, 1, 0};
const vector<int> dy = {0, 0, -1, 0, 1};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<bool>> ok(3000, vector<bool>(3000));
	int ans = 0;
	auto count = [&](pair<int, int> x) -> int {
		int cnt = 0;
		for(int i = 1; i < 5; ++i) {
			if(ok[x.f + dx[i] + 1500][x.s + dy[i] + 1500]) {
				++cnt;
			}
		}
		return cnt;
	};
	auto get = [&](pair<int, int> x) -> vector<pair<int, int>> {
		vector<pair<int, int>> hld;
		for(int i = 1; i < 5; ++i) {
			if(!ok[x.f + dx[i] + 1500][x.s + dy[i] + 1500]) {
				hld.pb(make_pair(x.f + dx[i], x.s + dy[i]));
			}
		}
		return hld;
	};
	function<void(pair<int, int>)> add = [&](pair<int, int> x) -> void {
		ok[x.f + 1500][x.s + 1500] = true;
		for(int i = 0; i < 5; ++i) {
			pair<int, int> y = make_pair(x.f + dx[i], x.s + dy[i]);
			if(ok[y.f + 1500][y.s + 1500] && count(y) == 3) {
				vector<pair<int, int>> hld = get(y);
				++ans;
				add(hld[0]);
			}
		}
	};
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if(ok[x + 1500][y + 1500]) {
			--ans;
		} else {
			ok[x + 1500][y + 1500] = true;
			add(make_pair(x, y));
		}
		cout << ans << nl;
	}
}
