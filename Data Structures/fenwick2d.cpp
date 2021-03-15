template <class T>
struct fenwick2d {
	int n;
	vector<vector<T>> tree;
	fenwick2d(const vector<vector<T>>& a) {
		n = si(a);
		tree.resize(n + 1, vector<T>(n + 1));
		for(int i = 0; i < si(a); ++i) {
			for(int j = 0; j < si(a[i]); ++j) {
				update(i, j, a[i][j]);
			}
		}
	}
	void update(int x, int y, int dif) {
		++x, ++y;
		for(int i = x; i <= n; i += (i & -i)) {
			for(int j = y; j <= n; j += (j & -j)) {
				tree[i][j] += dif;
			}
		}
	}
	T query(int x, int y) {
		++x, ++y;
		T sum = 0;
		for(int i = x; i > 0; i -= (i & -i)) {
			for(int j = y; j > 0; j -= (j & -j)) {
				sum += tree[i][j];
			}
		}
		return sum;
	}
	T query(int x, int y, int x1, int y1) {
		return query(x1, y1) - query(x1, y - 1) - query(x - 1, y1) + query(x - 1, y - 1);
	}
};
