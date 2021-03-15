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

template <class T>
T power(T a, int p) {
	T ans = 1, hld = a;
	assert(p >= 0);
	while(p > 0) {
		if(p & 1) {
			ans *= hld;
		}
		hld *= hld;
		p >>= 1;
	}
	return ans;
}

const int N = 1e6 + 10;

vector<mint> fac(N + 10);

mint C(int n, int k) {
	return fac[n] * inv(fac[n - k] * fac[k]);
}

void precomp() {
	fac[0] = fac[1] = 1;
	for(int i = 2; i <= N + 2; ++i) {
		fac[i] = (mint)i * fac[i - 1];
	}
}
