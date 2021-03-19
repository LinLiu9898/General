template <int MD>
struct modint {
	static const int mod = MD;
	int v;

	explicit operator int() const {
		return v;
	}
	modint() {
		v = 0;
	}
	modint(int _v) {
		v = (-MD < _v && _v < MD) ? _v : _v % MD;
		if(v < 0) {
			v += MD;
		}
	}

	friend bool operator == (const modint& a, const modint& b) {
		return a.v == b.v;
	}
	friend bool operator != (const modint& a, const modint& b) {
		return !(a == b);
	}
	friend bool operator < (const modint& a, const modint& b) {
		return a.v < b.v;
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
		if((v += m.v) >= MD) {
			v -= MD;
		}
		return *this;
	}
	modint& operator -= (const modint& m) {
		if((v -= m.v) < 0) {
			v += MD;
		}
		return *this;
	}
	modint& operator *= (const modint& m) {
		v = v * m.v % MD;
		return *this;
	}
	modint& operator /= (const modint& m) {
		return (*this) *= inv(m);
	}

	friend modint inv(const modint& a) {
		assert(a.v != 0);
		return power(a, MD - 2);
	}
	friend modint power(modint a, int p) {
		modint res = 1;
		assert(p >= 0);
		for(; p; p >>= 1, a *= a) {
			if(p & 1) {
				res *= a;
			}
		}
		return res;
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

const int N = 1e6 + 10;

bool is_precomped = false;

vector<mint> fac(N + 10), ifac(N + 10);

mint C(int n, int k) {
	assert(is_precomped);
	if(k < 0 || k > n) {
		return 0;
	}
	return fac[n] * ifac[k] * ifac[n - k];
}

void precomp() {
	is_precomped = true;
	fac[0] = fac[1] = 1;
	for(int i = 2; i < N + 10; ++i) {
		fac[i] = (mint)i * fac[i - 1];
	}
	ifac.back() = (mint)1 / fac.back();
	for(int i = N + 9; i > 0; --i) {
		ifac[i - 1] = i * ifac[i];
	}
}
