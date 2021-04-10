struct diam {
	int n;
	vector<vector<int>> adj;
	vector<int> par, depth;
	array<int, 3> tree_diam = {0, 0, -INF};

	diam(int _n) {
		init(_n);
	}
	
	diam(const vector<vector<int>>& _adj) {
		init(si(_adj));
		adj = _adj;
	}

	void init(int _n) {
		n = _n + 5;
		adj.assign(n, {});
		par.resize(n);
		depth.resize(n);
	}

	void add(int u, int v) {
		adj[u].pb(v);
		adj[v].pb(u);
	}

	void dfs(int u) {
		trav(i, adj[u]) {
			if(i != par[u]) {
				par[i] = u;
				depth[i] = depth[u] + 1;
				dfs(i);
			}
		}
	}

	void gen_dist(int u) {
		par[u] = -1;
		depth[u] = 0;
		dfs(u);
	}

	array<int, 3> get_diam() {
		gen_dist(0LL);
		for(int i = 0; i < n; ++i) {
			if(depth[i] > depth[tree_diam[0]]) {
				tree_diam[0] = i;
			}
		}
		gen_dist(tree_diam[0]);
		for(int i = 0; i < n; ++i) {
			if(depth[i] > depth[tree_diam[1]]) {
				tree_diam[1] = i;
			}
		}
		tree_diam[2] = depth[tree_diam[1]];
		return tree_diam;
	}
};
