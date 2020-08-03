const int base = 1e9,
    base_digits = 9;
struct bigint { // value == 0 is represented by empty z
    vi z; // digits
    int sign; // sign == 1 <==> value >= 0
    bigint(): sign(1) {} // sign == -1 <==> value < 0
    bigint(ll v) {
        * this = v;
    }
    bigint & operator = (ll v) {
        sign = v < 0 ? -1 : 1;
        v *= sign; // make v positive
        z.clear();
        for (; v; v /= base) z.pb(v % base);
        return *this;
    }
    bigint(const str & s) {
        read(s);
    } // add char by char

    bigint & operator += (const bigint & other) {
        //dbg("ADDING",*this,other,sign,other.sign);
        if (sign == other.sign) {
            for (int i = 0, carry = 0; i < si(other.z) || carry; ++i) {
                if (i == si(z)) z.pb(0);
                z[i] += carry + (i < si(other.z) ? other.z[i] : 0);
                carry = z[i] >= base;
                if (carry) z[i] -= base;
            }
        } else if (other != 0 /* prevent infinite loop */ ) * this -= -other;
        return *this;
    }
    friend bigint operator + (bigint a,
        const bigint & b) {
        return a += b;
    }
    bigint & operator -= (const bigint & other) {
        if (sign == other.sign) {
            if ((sign == 1 && * this >= other) || (sign == -1 && * this <= other)) {
                for (int i = 0, carry = 0; i < si(other.z) || carry; ++i) {
                    z[i] -= carry + (i < si(other.z) ? other.z[i] : 0);
                    carry = z[i] < 0;
                    if (carry) z[i] += base;
                }
                trim();
            } else { // result will change sign
                * this = other - * this;
                this -> sign = -this -> sign;
            }
        } else *this += -other;
        return *this;
    }
    friend bigint operator - (bigint a,
        const bigint & b) {
        return a -= b;
    }

    bigint & operator *= (int v) { // oops make sure not to multiply by ll ...
        if (v < 0) sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < si(z) || carry; ++i) {
            if (i == si(z)) z.pb(0);
            ll cur = (ll) z[i] * v + carry;
            carry = cur / base;
            z[i] = cur % base;
        }
        trim();
        return *this;
    }
    bigint operator * (int v) const {
        return bigint( * this) *= v;
    }
    friend pair < bigint, bigint > divmod(const bigint & a1,
        const bigint & b1) {
        int norm = base / (b1.z.back() + 1);
        bigint a = a1.abs() * norm, b = b1.abs() * norm, q, r; // make last element of b big
        q.z.rs(si(a.z));
        R0F(i, si(a.z)) {
            r *= base;
            r += a.z[i];
            int s1 = si(b.z) < si(r.z) ? r.z[si(b.z)] : 0;
            int s2 = si(b.z) - 1 < si(r.z) ? r.z[si(b.z) - 1] : 0;
            int d = ((ll) s1 * base + s2) / b.z.back(); // best approximation
            r -= b * d;
            while (r < 0) r += b, --d;
            q.z[i] = d;
        }
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return {
            q,
            r / norm
        };
    }
    friend bigint sqrt(const bigint & a1) {
        bigint a = a1;
        while (!si(a.z) || si(a.z) & 1) a.z.pb(0);
        int n = si(a.z), firstDigit = ::sqrt((db) a.z[n - 1] * base + a.z[n - 2]);
        int norm = base / (firstDigit + 1);
        a *= norm;
        a *= norm;
        while (!si(a.z) || si(a.z) & 1) a.z.pb(0);
        bigint r = (ll) a.z[n - 1] * base + a.z[n - 2];
        firstDigit = (int)::sqrt((db) a.z[n - 1] * base + a.z[n - 2]);
        int q = firstDigit;
        bigint res;
        R0F(j, n / 2) {
            for (;; --q) {
                bigint r1 = (r - (res * 2 * base + q) * q) * base * base +
                    (j > 0 ? (ll) a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);
                if (r1 >= 0) {
                    r = r1;
                    break;
                }
            }
            res *= base;
            res += q; // add a bit to sqrt
            if (j > 0) {
                int d1 = si(res.z) + 2 < si(r.z) ? r.z[si(res.z) + 2] : 0; // always 0/1?
                int d2 = si(res.z) + 1 < si(r.z) ? r.z[si(res.z) + 1] : 0;
                int d3 = si(res.z) < si(r.z) ? r.z[si(res.z)] : 0;
                q = ((ll) d1 * base * base + (ll) d2 * base + d3) / (firstDigit * 2);
            }
        }
        res.trim();
        return res / norm;
    }
    bigint operator / (const bigint & v) const {
        return divmod( * this, v).f;
    }
    bigint operator % (const bigint & v) const {
        return divmod( * this, v).s;
    }
    bigint & operator /= (int v) {
        if (v < 0) sign = -sign, v = -v;
        for (int i = si(z) - 1, rem = 0; i >= 0; --i) {
            ll cur = z[i] + rem * (ll) base;
            z[i] = cur / v;
            rem = cur % v;
        }
        trim();
        return *this;
    }
    bigint operator / (int v) const {
        return bigint( * this) /= v;
    }
    int operator % (int v) const {
        if (v < 0) v = -v;
        int m = 0;
        R0F(i, si(z)) m = (z[i] + m * (ll) base) % v;
        return m * sign;
    }
    bigint & operator *= (const bigint & v) {
        return *this = * this * v;
    }
    bigint & operator /= (const bigint & v) {
        return *this = * this / v;
    }

    bool operator < (const bigint & v) const {
        if (sign != v.sign) return sign < v.sign;
        if (si(z) != si(v.z)) return si(z) * sign < si(v.z) * v.sign;
        R0F(i, si(z)) if (z[i] != v.z[i]) return z[i] * sign < v.z[i] * sign;
        return 0; // equal
    }
    bool operator > (const bigint & v) const {
        return v < * this;
    }
    bool operator <= (const bigint & v) const {
        return !(v < * this);
    }
    bool operator >= (const bigint & v) const {
        return !( * this < v);
    }
    bool operator == (const bigint & v) const {
        return !( * this < v) && !(v < * this);
    }
    bool operator != (const bigint & v) const {
        return *this < v || v < * this;
    }
    void trim() {
        while (si(z) && z.back() == 0) z.pop_back();
        if (!si(z)) sign = 1; // don't output -0
    }
    bool isZero() const {
        return !si(z);
    }
    friend bigint operator - (bigint v) {
        if (si(v.z)) v.sign = -v.sign;
        return v;
    }
    bigint abs() const {
        return sign == 1 ? * this : - * this;
    }
    ll longValue() const {
        ll res = 0;
        R0F(i, si(z)) res = res * base + z[i];
        return res * sign;
    }
    friend bigint gcd(const bigint & a,
        const bigint & b) {
        return b.isZero() ? a : gcd(b, a % b);
    } // euclidean algo
    friend bigint lcm(const bigint & a,
        const bigint & b) {
        return a / gcd(a, b) * b;
    }

    void read(const str & s) {
        sign = 1;
        z.clear();
        int pos = 0;
        while (pos < si(s) && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-') sign = -sign;
            ++pos;
        } // account for sign
        for (int i = si(s) - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            z.pb(x);
        }
        trim();
    }
    friend istream & operator >> (istream & is, bigint & v) {
        str s;
        is >> s;
        v.read(s);
        return is;
    }
    friend ostream & operator << (ostream & os,
        const bigint & v) {
        if (v.sign == -1) os << '-';
        os << (!si(v.z) ? 0 : v.z.back());
        R0F(i, si(v.z) - 1) os << setw(base_digits) << setfill('0') << v.z[i];
        return os; // pad with zeroes
    }
    static vi convert_base(const vi & a, int old_digits, int new_digits) {
        vl p(max(old_digits, new_digits) + 1); // blocks of 10^{old} -> 10^{new}
        p[0] = 1;
        FOR(i, 1, si(p)) p[i] = p[i - 1] * 10;
        vi res;
        ll cur = 0;
        int cur_digits = 0;
        for (int v: a) {
            cur += v * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.pb(cur % p[new_digits]);
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.pb(cur);
        while (si(res) && res.back() == 0) res.pop_back();
        return res;
    }
    static vl karatMul(const vl & a,
        const vl & b) { // karatsuba
        int n = si(a);
        vl res(2 * n);
        if (n <= 32) { // naive multiply
            F0R(i, n) F0R(j, n) res[i + j] += a[i] * b[j];
            return res;
        }
        int k = n / 2;
        vl a1(begin(a), begin(a) + k), a2(k + all(a));
        vl b1(begin(b), begin(b) + k), b2(k + all(b));
        vl a1b1 = karatMul(a1, b1), a2b2 = karatMul(a2, b2);
        F0R(i, k) a2[i] += a1[i], b2[i] += b1[i];
        vl r = karatMul(a2, b2); // three instead of four products
        F0R(i, si(a1b1)) r[i] -= a1b1[i];
        F0R(i, si(a2b2)) r[i] -= a2b2[i];
        F0R(i, si(r)) res[i + k] += r[i];
        F0R(i, si(a1b1)) res[i] += a1b1[i];
        F0R(i, si(a2b2)) res[i + n] += a2b2[i];
        return res;
    }
    bigint operator * (const bigint & v) const {
        if (min(si(z), si(v.z)) < 150) return mul_simple(v);
        bigint res;
        res.sign = sign * v.sign; // should work as long as # of digits isn't too large (> LLONG_MAX/10^{12})
        vi a6 = convert_base(this -> z, base_digits, 6); // blocks of 10^6 instead of 10^9
        vi b6 = convert_base(v.z, base_digits, 6);
        vl a(all(a6)), b(all(b6));
        while (si(a) < si(b)) a.pb(0);
        while (si(b) < si(a)) b.pb(0);
        while (si(a) & (si(a) - 1)) a.pb(0), b.pb(0); // make size power of 2
        vl c = karatMul(a, b);
        ll cur = 0;
        F0R(i, si(c)) { // process carries
            cur += c[i];
            res.z.pb(cur % 1000000);
            cur /= 1000000;
        }
        res.z = convert_base(res.z, 6, base_digits);
        res.trim();
        return res;
    }
    bigint mul_simple(const bigint & v) const {
		bigint res;
		res.sign = sign * v.sign;
		res.z.rs(si(z) + si(v.z));
		F0R(i, si(z))
			if(z[i]) {
				ll cur = 0;
				for(int j = 0; j < si(v.z) || cur; ++j) {
					cur += res.z[i + j] + (ll) z[i] * (j < si(v.z) ? v.z[j] : 0);
					res.z[i + j] = cur % base;
					cur /= base;
				}
			}
		res.trim();
		return res;
	}
	friend str ts(const bigint & v) {
		stringstream ss;
		ss << v;
		str s;
		ss >> s;
		return s;
    }
};
