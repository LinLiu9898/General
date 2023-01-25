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

	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> a;
	for(int i = 0; i < si(s); ++i) {
		a.pb(int(s[i] - 'A'));
	}
	auto check = [&](vector<int> x) -> vector<int> {
		vector<int> last_occ(26, -1LL);
		vector<int> ans = {1};
		last_occ[x[0]] = 0;
		for(int i = 1; i < n; ++i) {
			bool ok = false;
			for(int j = 0; j < x[i]; ++j) {
				if(last_occ[x[i]] == -1 || last_occ[j] > last_occ[x[i]]) {
					ok = true;
				}
			}
			if(last_occ[x[i]] == -1 || ok) {
				ans.pb(ans.back() + 1);
			} else {
				ans.pb(ans.back());
			}
			last_occ[x[i]] = i;
		}
		return ans;
	};
	vector<int> hld = check(a);
	reverse(all(a));
	vector<int> hld1 = check(a);
	reverse(all(hld1));
	for(int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		cout << (l == 0 ? 0 : hld[l - 1]) + (r == n - 1 ? 0 : hld1[r + 1]) << nl;
	}
}
