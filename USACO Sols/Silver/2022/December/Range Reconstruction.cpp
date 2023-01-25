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
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < i; ++j) {
			a[i][j] = 0;
		}
		for(int j = i; j < n; ++j) {
			cin >> a[i][j];
		}
		
	}
	vector<int> ans = {1};
	int curma = 1, curmi = 1;
	int lastma = 0, lastmi = 0;
	for(int i = 1; i < n; ++i) {
		int x = a[i - 1][i];
		ans.pb(ans.back() + x);
		lastma = curma;
		lastmi = curmi;
		curma = max(curma, ans.back());
		curmi = min(curmi, ans.back());
		bool ok = true;
		for(int j = 0; j < i; ++j) {
			int cur = a[j][i];
			int curmi1 = INF, curma1 = -INF;
			for(int h = j; h <= i; ++h) {
				curmi1 = min(curmi1, ans[h]);
				curma1 = max(curma1, ans[h]);
			}
			if(curma1 - curmi1 != cur) {
				ok = false;
				break;
			}
		}
		if(ok) {
			continue;
		}
		ans.pop_back();
		ans.pb(ans.back() - x);
		curma = lastma;
		curmi = lastmi;
		curma = max(curma, ans.back());
		curmi = min(curmi, ans.back());
		ok = true;
		for(int j = 0; j < i; ++j) {
			int cur = a[j][i];
			int curmi1 = INF, curma1 = -INF;
			for(int h = j; h <= i; ++h) {
				curmi1 = min(curmi1, ans[h]);
				curma1 = max(curma1, ans[h]);
			}
			if(curma1 - curmi1 != cur) {
				ok = false;
				break;
			}
		}
	}
	if(curmi < -1e9) {
		int dif = -1e9 - curmi;
		trav(i, ans) {
			i += dif;
		}
	}
	if(curma > 1e9) {
		int dif = 1e9 - curma;
		trav(i, ans) {
			i += dif;
		}
	}
	cout << ans[0];
	for(int i = 1; i < si(ans); ++i) {
		cout << " " << ans[i];
	}
}
