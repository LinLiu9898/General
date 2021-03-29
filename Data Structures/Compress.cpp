vector<int> coord_compress;

void compress(vector<coord_compress> x) {
	coord_compress = x;
	sort(all(coord_compress));
	coord_compress.resize(unique(all(coord_compress)) - coord_compress.begin());
}
int get(int x) {
	int pos = lower_bound(all(coord_compress), x) - coord_compress.begin();
	assert(coord_compress[pos] == x);
	return pos;
}
