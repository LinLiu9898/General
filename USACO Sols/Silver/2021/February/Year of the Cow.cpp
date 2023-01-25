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

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	trav(i, a) {
		cin >> i;
	}
	sort(all(a));
	set<pair<int, int>> se;
	for(int i = 0; i < n; ++i) {
		int x = -1, y = -1;
		for(int j = a[i]; j < a[i] + 12; ++j) {
			if(j % 12 == 0) {
				x = j;
				break;
			}
		}
		for(int j = a[i] - 1; j >= a[i] - 12; --j) {
			if(j % 12 == 0) {
				y = j;
				break;
			}
		}
		se.ins(make_pair(x, y));
	}
	se.ins(make_pair(0, 0));
	vector<pair<int, int>> b;
	trav(i, se) {
		b.pb(i);
	}
	reverse(all(b));
	k--;
	vector<int> dif;
	for(int i = 0; i < si(b) - 1; ++i) {
		dif.pb(b[i].s - b[i + 1].f);
	}
	sort(rall(dif));
	int sum = 0;
	for(int i = 0; i < k; ++i) {
		sum += dif[i];
	}
	cout << b[0].f - sum << nl;
}
