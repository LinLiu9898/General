vector<int> cnt;

void compress(vector<int> x) {
	cnt = x;
	sort(all(cnt));
	cnt.resize(unique(all(cnt)) - cnt.begin());
}
int get(int x) {
	int pos = lower_bound(all(cnt), x) - cnt.begin();
	assert(cnt[pos] == x);
	return pos;
}
