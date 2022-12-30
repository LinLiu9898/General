// Reference: https://codeforces.com/contest/1731/submission/187198977

vector<int> log(n + 1);
	for(int i = 2; i < n + 1; ++i) {
		log[i] = log[i / 2] + 1;
	}
	vector<vector<vector<int>>> st(n, vector<vector<int>>(m, vector<int>(log[n] + 2)));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			st[i][j][0] = a[i][j];
		}
	}
	for(int i = 1; (1LL << i) <= n; ++i) {
		for(int j = (1LL << i) - 1; j < n; ++j) {
			for(int h = (1LL << i) - 1; h < m; ++h) {
				st[j][h][i] = min({st[j][h][i - 1], st[j - (1LL << (i - 1))][h - (1LL << (i - 1))][i - 1], st[j][h - (1LL << (i - 1))][i - 1], st[j - (1LL << (i - 1))][h][i - 1]});
			}
		}
	}
	auto query = [&](int x1, int y1, int x2, int y2) -> int {
		assert(x2 - x1 == y2 - y1);
		int len = x2 - x1 + 1;
		int cur = log[len];
		return min({st[x2][y2][cur], st[x1 + (1LL << cur) - 1][y2][cur], st[x2][y1 + (1LL << cur) - 1][cur], st[x1 + (1LL << cur) - 1][y1 + (1LL << cur) - 1][cur]});
	};
