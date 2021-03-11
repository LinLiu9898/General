template <class T>
struct fenwick {
	int n;
	vector<int> tree;
	fenwick(const vector<int>& a) {
		n = si(a);
		tree.resize(n + 2);
		for(int i = 0; i < si(a); ++i) {
			update(i, a[i]);
		}
	}
	void update(int pos, int dif) {
		++pos;
		for(int i = pos; i <= n; i += (i & -i)) {
			tree[i] += dif;
		}
	}
	void set(int pos, int val) {
		update(pos, val - query(pos, pos));
	}
	int query(int l) {
		++l;
		int sum = 0;
		for(int i = l; i > 0; i -= (i & -i)) {
			sum += tree[i];
		}
		return sum;
	}
	int query(int l, int r) {
		return query(r) - query(l - 1);
	}
};
