vector<int> z(string s) {
	int n = si(s);
	vector<int> z(n);
	int x = 0. y = 0;
	z[0] = si(s);
	for(int i = 1; i < n; ++i) {
		z[i] = max(0LL, min(z[i - x], y - i + 1));
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			x = i;
			y = i + z[i];
			++z[i];
		}
	}
	return z;
}
