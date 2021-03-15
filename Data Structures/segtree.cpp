template <class T>
struct segtree {
	int n = 1;
	vector<T> tree;
	T comb(T a, T b) {
		return a + b;
	}
	segtree(vector<int> a) {
		while(n < si(a)) {
			n *= 2;
		}
		while(si(a) < n) {
			a.pb(0LL);
		}
		assert(si(a) == n);
		tree.resize(2 * n + 2);
		for(int i = n - 1; i < 2 * n - 1; ++i) {
			tree[i] = a[i - n + 1];
		}
		for(int i = n - 2; i >= 0; --i) {
			tree[i] = comb(tree[i * 2 + 1], tree[i * 2 + 2]);
		}
	}
	void add(int pos, int dif) {
		pos += n - 1;
		tree[pos] += dif;
		while(pos > 0) {
			pos = (pos - 1) / 2;
			tree[pos] = comb(tree[pos * 2 + 1], tree[pos * 2 + 2]);
		}
	}
	void set(int pos, int val) {
		add(pos, val - tree[pos + n - 1]);
	}
	int qry(int lx, int rx, int l, int r, int node) {
		if(lx >= l && rx <= r) {
			return tree[node];
		}
		if(rx < l || lx > r) {
			return 0;
		}
		int mid = (lx + rx) / 2;
		return comb(qry(lx, mid, l, r, node * 2 + 1), qry(mid + 1, rx, l, r, node * 2 + 2));
	}
	int query(int l, int r) {
		return qry(0, n - 1, l, r, 0);
	}
};
