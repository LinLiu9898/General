using ull = unsigned long long;
ull modmul(ull a, ull b, ull M) {
	int ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (int)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for(; e; b = modmul(b, b, mod), e /= 2) {
		if(e & 1) {
			ans = modmul(ans, b, mod);
		}
	}
	return ans;
}
bool prime(ull n) {
	if(n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
		s = __builtin_ctzll(n - 1), d = n >> s;
	trav(a, A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while(p != 1 && p != n - 1 && a % n && i--) {
			p = modmul(p, p, n);
		}
		if(p != n - 1 && i != s) {
			return 0;
		}
	}
	return 1;
}
ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while(t++ % 40 || __gcd(prd, n) == 1) {
		if(x == y) x = ++i, y = f(x);
		if((q = modmul(prd, max(x, y) - min(x, y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<int> factor(int n) {
	if(n == 1) return {};
	if(prime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}
