template <class T>
struct fenwick2d {
	int n, m;
	vector<vector<T>> tree;
	const T ID = 0LL;
	fenwick2d(const int& _n, const int& _m) {
		n = _n;
		m = _m;
		tree.assign(n + 2, vector<T>(m + 2, ID));
	}
	void add(int x, int y, int dif) {
		for(int i = x + 1; i <= n; i += (i & -i)) {
			for(int j = y + 1; j <= n; j += (j & -j)) {
				tree[i][j] += dif;
			}
		}
	}
	T query(int x, int y) {
		T sum = 0;
		for(int i = x + 1; i > 0; i -= (i & -i)) {
			for(int j = y + 1; j > 0; j -= (j & -j)) {
				sum += tree[i][j];
			}
		}
		return sum;
	}
	T query(int x, int y, int x1, int y1) {
		return query(x1, y1) - query(x1, y - 1) - query(x - 1, y1) + query(x - 1, y - 1);
	}
};
