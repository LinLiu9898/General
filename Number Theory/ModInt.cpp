using ul = uint64_t;
using L = __uint128_t;
 
struct FastMod {
	ul b, m;
	FastMod(ul _b) : b(_b), m((ul)((L(1) << 64) / _b)) {}
	ul reduce(ul a) {
		if(b == 1) {
			return 0;
		}
		ul q = (ul)((L(m) * a) >> 64), r = a - q * b;
		return r >= b ? r - b : r;
	}
};
 
template <int id>
struct modint {
	int v;
	static FastMod FM;
 
	static int mod() {
		return (int)FM.b;
	}

	void set_mod(int mod) {
		v %= mod;
		if(v < 0LL) {
			v += mod;
		}
		assert(mod >= 1);
		FM = FastMod(mod);
	}

	explicit operator int() const {
		return v;
	}

	modint() {
		v = 0;
	}

	modint(int _v) {
		v = (-mod() < _v && _v < mod()) ? _v : _v % mod();
		if(v < 0) {
			v += mod();
		}
	}

	friend bool operator == (const modint& a, const modint& b) {
		return a.v == b.v;
	}

	friend bool operator != (const modint& a, const modint& b) {
		return !(a == b);
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
		v += m.v;
		if(v >= mod()) {
			v -= mod();
		}
		return *this;
	}

	modint& operator -= (const modint& m) {
		v -= m.v;
		if(v < 0) {
			v += mod();
		}
		return *this;
	}

	modint& operator *= (const modint& m) {
		v = (int)FM.reduce(v * m.v);
		return *this;
	}

	modint& operator /= (const modint& m) {
		return (*this) *= inv(m);
	}

	friend modint inv(const modint& a) {
		assert(a.v != 0);
		return power(a, mod() - 2);
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

template <int id>
FastMod modint<id>::FM = FastMod(MOD);

using mint = modint<0>;

const int N = 1e6 + 10;

bool is_precomped = false;
vector<mint> fac(N + 10), ifac(N + 10);

mint C(int n, int k) {
	assert(is_precomped && n < N);
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
}
