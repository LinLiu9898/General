template <class T>
struct DSU {
	vector<int> par, size;
	DSU(int n) {
		par = vector<int>(n + 10);
		size = vector<int>(n + 10, 1LL);
		for(int i = 0; i < n + 5; ++i) {
			par[i] = i;
		}
	}
	int find(int u) {
		return (par[u] == u ? u : par[u] = find(par[u]));
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
		}
	}
};
