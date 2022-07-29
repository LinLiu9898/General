// copied from Benq
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using H = array<int, 3>; // bases not too close to ends 
H makeH(char c) { return {c,c, c}; }
uniform_int_distribution<int> BDIST(0.1*MOD,0.9*MOD);
const H base{BDIST(rng),BDIST(rng),BDIST(rng)};
/// const T ibase = {(int)inv(mi(base[0])),(int)inv(mi(base[1]))};

H operator+(H l, H r) { 
	for(int i = 0; i < 3; ++i) if ((l[i] += r[i]) >= MOD) l[i] -= MOD;
	return l;
}
H operator-(H l, H r) { 
	for(int i = 0; i < 3; ++i) if ((l[i] -= r[i]) < 0) l[i] += MOD;
	return l; 
}
H operator*(H l, H r) { 
	for(int i = 0; i < 3; ++i) l[i] = (int)l[i]*r[i]%MOD;
	return l;
}
/// H& operator+=(H& l, H r) { return l = l+r; }
/// H& operator-=(H& l, H r) { return l = l-r; }
/// H& operator*=(H& l, H r) { return l = l*r; }

vector<H> pows{{1,1, 1}};
struct HashRange {
	string S; vector<H> cum{{}};
	void add(char c) { S += c; cum.pb(base*cum.back()+makeH(c)); }
	void add(string s) { trav(c,s) add(c); }
	void extend(int len) { while (si(pows) <= len) 
		pows.pb(base*pows.back()); }
	H hash(int l, int r) { int len = r+1-l; extend(len);
		return cum[r+1]-pows[len]*cum[l]; }
	/**int lcp(HashRange& b) { return first_true([&](int x) { 
	  return cum[x] != b.cum[x]; },0,min(sz(S),sz(b.S)))-1; }*/
};
/// HashRange HR; HR.add("ababab"); F0R(i,6) FOR(j,i,6) ps(i,j,HR.hash(i,j));
