template <class T> struct RMQ {
	vector<vector<T>> st;
	vector<int> log;
	
	T combine(T a, T b) {
		//return min(a, b);
	}

	RMQ(const vector<T>& a) {
		init(a);
	}

	void init(vector<T> a) {
		int n = si(a);
		log = vector<int>(n + 1);
		for(int i = 2; i <= n; ++i) {
			log[i] = log[i / 2] + 1;
		}
		int k = log[n];
		st = vector<vector<T>>(n, vector<T>(k + 1));
		for(int i = 0; i < n; ++i) {
			st[i][0] = a[i];
		}
		for(int j = 1; j <= k; ++j) {
			for(int i = 0; i + (1LL << j) - 1 < n; ++i) {
				st[i][j] = combine(st[i][j - 1], st[i + (1LL << (j - 1))][j - 1]);
			}
		}
	}

	T query(int l, int r) {
		int k = log[r - l + 1];
		return combine(st[l][k], st[r - (1LL << k) + 1][k]);
	}
};
