int modmul(int a, int b, int M) {
	int ret = a * b - M * (int)(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (int)M);
}

int modpow(int b, int e, int mod) {
	int ans = 1;
	for(; e; b = modmul(b, b, mod), e >>= 1) {
		if(e & 1) {
			ans = modmul(ans, b, mod);
		}
	}
	return ans;
}

bool prime(int n) {
	if(n < 2 || n  % 6 % 4 != 1) {
		return (n | 1) == 3;
	}
	vector<int> a = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	int s = __builtin_ctzll(n - 1), d = n >> s;
	trav(i, a) {
		int p = modpow(i % n, d, n), q = s;
		while(p != 1 && p != n - 1 && i % n && q--) {
			p = modmul(p, p, n);
		}
		if(p != n - 1 && q != s) {
			return false;
		}
	}
	return true;
}

int pollard(int n) {
	auto f = [n](int x) {
		return modmul(x, x, n) + 1;
	};
	int x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while(t++ % 40 || gcd(prd, n) == 1) {
		if(x == y) {
			x = ++i;
			y = f(x);
		}
		if((q = modmul(prd, max(x,y) - min(x,y), n))) {
			prd = q;
		}
		x = f(x);
		y = f(f(y));
	}
	return gcd(prd, n);
}

vector<int> factor(int n) {
	if(n == 1) {
		return {};
	}
	if(prime(n)) {
		return {n};
	}
	int x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}
