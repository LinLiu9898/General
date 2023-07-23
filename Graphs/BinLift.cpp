struct binlift {
	int n, d = 0, timer;
	vector<vector<int>> adj, par;
	vector<int> depth, tin, tout;
	bool is_built = false;

	binlift(int _n) {
		init(_n);
	}

	binlift(const vector<vector<int>>& _adj) {
		init(si(_adj));
		adj = _adj;
	}

	void init(int _n) {
		n = _n + 5;
		while((1 << d) <= _n) {
			++d;
		}
		adj.assign(n, {});
		par.assign(n, vector<int>(d));
		depth.assign(n, 0LL);
		tin.resize(n);
		tout.resize(n);
	}

	void add(int u, int v) {
		adj[u].pb(v);
		adj[v].pb(u);
	}

	void build() {
		dfs(0, -1);
		is_built = true;
	}

	void dfs(int u = 0, int p = -1) {
		tin[u] = timer++;
		for(int i = 1; i < d; ++i) {
			par[u][i] = par[par[u][i - 1]][i - 1];
		}
		trav(v, adj[u]) {
			if(v == p) {
				continue;
			}
			par[v][0] = u;
			depth[v] = depth[u] + 1;
			dfs(v, u);
		}
		tout[u] = timer - 1;
	}

	bool is_anc(int u, int v) { // returns if u is the ancestor of v
		assert(is_built && "call build function");
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	}

	int jump(int node, int k) {
		assert(is_built && "call build function");
		if(depth[node] < k) {
			return -1;
		}
		for(int j = d - 1; j >= 0; --j) {
			if(k >= (1 << j)) {
				node = par[node][j];
				k -= (1 << j);
			}
		}
		return node;
	}

	int lca(int u, int v) {
		assert(is_built && "call build function");
		if(is_anc(u, v)) {
			return u;
		}
		if(is_anc(v, u)) {
			return v;
		}
		for(int j = d - 1; j >= 0; --j) {
			int lift = par[u][j];
			if(!is_anc(lift, v)) {
				u = lift;
			}
		}
		return par[u][0];
	}

	int dist(int u, int v) {
		assert(is_built && "call build function");
		return depth[u] + depth[v] - 2 * depth[lca(u, v)];
	}
};
