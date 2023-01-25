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
	int curans = 0;
	int curans1 = 0;
	for(int i = 0; i < n; ++i) {
		int sum_even = 0, sum_odd = 0;
		for(int j = 0; j < n; ++j) {
			if(j % 2 == 0) {
				sum_even += a[j][i];
			} else {
				sum_odd += a[j][i];
			}
		}
		curans += max(sum_even, sum_odd);
	}
	for(int i = 0; i < n; ++i) {
		int sum_even = 0, sum_odd = 0;
		for(int j = 0; j < n; ++j) {
			if(j % 2 == 0) {
				sum_even += a[i][j];
			} else {
				sum_odd += a[i][j];
			}
		}
		curans1 += max(sum_even, sum_odd);
	}
	cout << max(curans, curans1) << nl;
}
