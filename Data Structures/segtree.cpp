struct item {

	static item neutral() {

	}

	template <class T>
	void init(T x) {

	}

	static item merge(item a, item b) {

	}
};

template <class T, class H = int>
struct segtree {
	int n = 1;
	vector<T> tree;
	const H unit = -1;

	segtree(int _n) {
		while(n < _n) {
			n *= 2;
		}
		tree = vector<T>(2 * n + 5, T());
	}

	void init(vector<H> a) {
		while(n < si(a)) {
			n *= 2;
		}
		for(int i = si(a); i < n; ++i) {
			a.pb(unit);
		}
		assert(si(a) == n);
		tree.resize(2 * n + 2);
		for(int i = n - 1; i < 2 * n - 1; ++i) {
			tree[i].init(a[i - n + 1]);
		}
		for(int i = n - 2; i >= 0; --i) {
			tree[i] = T::merge(tree[i * 2 + 1], tree[i * 2 + 2]);
		}
	}

	void set(int pos, H val) {
		pos += n - 1;
		tree[pos].init(val);
		while(pos) {
			pos = (pos - 1) / 2;
			tree[pos] = T::merge(tree[pos * 2 + 1], tree[pos * 2 + 2]);
		}
	}

	T query(int lx, int rx, int l, int r, int node) {
		if(lx >= l && rx <= r) {
			return tree[node];
		}
		if(rx < l || lx > r) {
			return T::neutral();
		}
		int mid = (lx + rx) / 2;
		return T::merge(query(lx, mid, l, r, node * 2 + 1), query(mid + 1, rx, l, r, node * 2 + 2));
	}

	T query(int l, int r) {
		l = max(l, int(0));
		r = min(r, n - 1);
		if(l > r) {
			return T();
		}
		return query(0, n - 1, l, r, 0);
	}
};
