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

template <class T>
struct DSU {
	vector<int> par, size;
	vector<vector<int>> group;
	DSU(int n) {
		init(n);
	}

	void init(int n) {
		par = vector<int>(n + 10);
		size = vector<int>(n + 10, 1LL);
		group = vector<vector<int>>(n + 10);
		for(int i = 0; i < n + 5; ++i) {
			par[i] = i;
			group[i] = {i};
		}
	}

	int find(int u) {
		return (par[u] == u ? u : par[u] = find(par[u]));
	}

	bool same(int u, int v) {
		return find(u) == find(v);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if(u != v) {
			if(size[u] < size[v]) {
				swap(u, v);
			}
			par[v] = u;
			size[u] += size[v];
			trav(i, group[v]) {
				group[u].pb(i);
			}
			while(si(group[v])) {
				group[v].pop_back();
			}
		}
	}
};


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		a[i] = i;
	}
	vector<vector<int>> pos(n);
	for(int i = 0; i < n; ++i) {
		pos[i].pb(i);
	}
	for(int i = 0; i < k; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		pos[a[u]].pb(v);
		pos[a[v]].pb(u);
		swap(a[v], a[u]);
	}
	for(int i = 0; i < n; ++i) {
		sort(all(pos[i]));
		pos[i].resize(unique(all(pos[i])) - pos[i].begin());
	}
	DSU<int> dsu(n);
	for(int i = 0; i < n; ++i) {
		dsu.merge(i, a[i]);
	}
	vector<bool> vis(n, false);
	vector<int> ans(n);
	for(int i = 0; i < n; ++i) {
		int cur = dsu.find(i);
		if(vis[cur]) {
			cout << ans[cur] << nl;
			continue;
		}
		vis[cur] = true;
		set<int> se;
		trav(j, dsu.group[cur]) {
			trav(h, pos[j]) {
				se.ins(h);
			}
		}
		ans[cur] = si(se);
		cout << ans[cur] << nl;
	}
}
