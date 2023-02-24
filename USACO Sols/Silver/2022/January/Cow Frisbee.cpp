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
	vector<int> a(n);
	trav(i, a) {
		cin >> i;
	}
	auto ans = [&]() -> int {
		int cur = 0;
		stack<pair<int, int>> st;
		for(int i = n - 1; i >= 0; --i) {
			while(si(st) && st.top().first <= a[i]) {
				st.pop();
			}
			if(si(st)) {
				cur += st.top().second - i + 1;
			}
			st.push({a[i], i});
		}
		return cur;
	};
	int curans = ans();
	reverse(all(a));
	cout << curans + ans() << nl;
}
