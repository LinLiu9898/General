template <class T>
struct fenwick {
	int n;
	vector<T> tree;
	const T ID = 0LL;
	fenwick(const int& _n) {
		n = _n;
		tree.assign(n + 2, ID);
	}
	void add(int pos, T dif) {
		for(int i = pos + 1; i <= n; i += (i & -i)) {
			tree[i] += dif;
		}
	}
	void set(int pos, T val) {
		add(pos, val - query(pos, pos));
	}
	T query(int l) {
		T sum = 0;
		for(int i = l + 1; i > 0; i -= (i & -i)) {
			sum += tree[i];
		}
		return sum;
	}
	T query(int l, int r) {
		return query(r) - query(l - 1);
	}
};
