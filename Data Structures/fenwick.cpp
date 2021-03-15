template <class T>
struct fenwick {
	int n;
	vector<T> tree;
	fenwick(const vector<T>& a) {
		n = si(a);
		tree.resize(n + 2);
		for(int i = 0; i < si(a); ++i) {
			update(i, a[i]);
		}
	}
	void update(int pos, T dif) {
		++pos;
		for(int i = pos; i <= n; i += (i & -i)) {
			tree[i] += dif;
		}
	}
	void set(int pos, T val) {
		update(pos, val - query(pos, pos));
	}
	T query(int l) {
		++l;
		T sum = 0;
		for(int i = l; i > 0; i -= (i & -i)) {
			sum += tree[i];
		}
		return sum;
	}
	T query(int l, int r) {
		return query(r) - query(l - 1);
	}
};
