template <class T>
T power(T a, int p) {
	T ans = 1;
	assert(p >= 0);
	for(; p; a *= a, p >>= 1) {
		if(p & 1) {
			ans *= a;
		}
	}
	return ans;
}

template <int mod = MOD> struct modint {
	int v;

	modint() : v(0) {}
	modint(int _v) {
		v = (-mod < _v && _v < mod) ? _v : _v % mod;
		if(v < 0) {
			v += mod;
		}
	}

	explicit operator int() const {
		return v;
	}

	bool operator == (const modint& a) {
		return v == a.v;
	}
	bool operator != (const modint& a) {
		return v != a.v;
	}

	friend ostream& operator << (ostream& os, const modint& m) {
		os << m.v;
		return os;
	}
	friend istream& operator >> (istream& is, modint& m) {
		int x;
		is >> x;
		m.v = x;
		return is;
	}

	modint& operator += (const modint& m) {
		if((v += m.v) >= mod) {
			v -= mod;
		}
		return *this;
	}
	modint& operator -= (const modint& m) {
		if((v -= m.v) < 0) {
			v += mod;
		}
		return *this;
	}
	modint& operator *= (const modint& m) {
		v = v * m.v % mod;
		return *this;
	}
	modint& operator /= (const modint& m) {
		return (*this) *= m.inv();
	}
	modint inv() const {
		return power(modint(v), mod - 2);
	}
	modint operator - () const {
		return modint(-v);
	}
	modint& operator ++ () {
		return *this += 1;
	}
	modint& operator -- () {
		return *this -= 1;
	}
	friend modint operator + (modint a, const modint& b) {
		return a += b;
	}
	friend modint operator - (modint a, const modint& b) {
		return a -= b;
	}
	friend modint operator * (modint a, const modint& b) {
		return a *= b;
	}
	friend modint operator / (modint a, const modint& b) {
		return a /= b;
	}
};

using mint = modint<MOD>;

/*
const int N = 2;

bool is_precomped = false;

vector<mint> fac(N + 10), ifac(N + 10);

mint C(int n, int k) {
	assert(is_precomped && "call precomp, retard");
	if(k < 0 || k > n) {
		return 0;
	}
	return fac[n] * ifac[k] * ifac[n - k];
}

void precomp() {
	if(is_precomped) {
		return;
	}
	is_precomped = true;
	fac[0] = fac[1] = 1;
	for(int i = 2; i < N + 10; ++i) {
		fac[i] = (mint)i * fac[i - 1];
	}
	ifac.back() = (mint)1 / fac.back();
	for(int i = N + 9; i > 0; --i) {
		ifac[i - 1] = i * ifac[i];
	}
}*/
