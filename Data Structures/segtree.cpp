template <class T>
struct segtree {
	int n = 1;
	vector<T> tree;
	const T unit = 0LL;
	// comb(a, unit) = a
	T comb(T a, T b) {
		return a + b;
	}
	segtree(vector<T> a) {
		init(a);
	}
	void init(vector<T> a) {
		while(n < si(a)) {
			n *= 2;
		}
		for(int i = si(a); i < n; ++i) {
			a.pb(unit);
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
	void set(int pos, T val) {
		pos += n - 1;
		tree[pos] = val;
		while(pos) {
			pos = (pos - 1) / 2;
			tree[pos] = comb(tree[pos * 2 + 1], tree[pos * 2 + 2]);
		}
	}
	T query(int lx, int rx, int l, int r, int node) {
		if(lx >= l && rx <= r) {
			return tree[node];
		}
		if(rx < l || lx > r) {
			return unit;
		}
		int mid = (lx + rx) / 2;
		return comb(query(lx, mid, l, r, node * 2 + 1), query(mid + 1, rx, l, r, node * 2 + 2));
	}
	T query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}
};
