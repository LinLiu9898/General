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



int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	trav(i, a) {
		trav(j, i) {
			cin >> j;
		}
	}
	auto calc = [&](int x) -> int {
		vector<vector<int>> b(n, vector<int>(n));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				for(int h = i; h >= 0; --h) {
					if(a[h][j] < x) {
						break;
					} else {
						++b[i][j];
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				int cur = INF;
				for(int h = j; h >= 0; --h) {
					cur = min(cur, b[i][h]);
					ans += cur;
				}
			}
		}
		return ans;
	};
	cout << calc(100) - calc(101) << nl;
}
