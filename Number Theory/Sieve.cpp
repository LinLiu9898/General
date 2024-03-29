int cur_generated;
vector<bool> isprime;
vector<int> primes, spf;
bool is_built_sieve = false;

void sieve(int maximum) {
	if(is_built_sieve) {
		assert(false && "Why build sieve again?");
	}
	cur_generated = maximum;
	isprime.assign(maximum + 5, true);
	isprime[0] = isprime[1] = false;
	spf.resize(maximum + 5);
	iota(all(spf), 0LL);
	for(int i = 2; i * i <= maximum + 1; ++i) {
		if(isprime[i]) {
			spf[i] = i;
			for(int j = i * i; j <= maximum + 1; j += i) {
				if(isprime[j]) {
					isprime[j] = false;
					spf[j] = i;
				}
			}
		}
	}
	for(int i = 0; i < maximum; ++i) {
		if(isprime[i]) {
			primes.pb(i);
		}
	}
	is_built_sieve = true;
}

vector<array<int, 2>> factor(int n) {
	assert(is_built_sieve);
	int cur_ma = cur_generated;
	assert(n > 0 && n <= cur_ma * cur_ma);
	vector<array<int, 2>> res;
	if(n <= cur_ma) {
		while(n > 1) {
			int p = spf[n], expo = 0;
			do {
				n /= p;
				++expo;
			} while(n % p == 0);
			res.pb({p, expo});
		}
		return res;
	}
	trav(p, primes) {
		if(p * p > n) {
			break;
		}
		if(n % p == 0) {
			res.pb({p, 0});
			while(n % p == 0) {
				n /= p;
				++res.back()[1];
			}
		}
	}
	if(n > 1) {
		res.pb({n, 1});
	}
	return res;
}

int phi(int x) {
	vector<array<int, 2>> v = factor(x);
	trav(i, v) {
		x = x / i[0] * (i[0] - 1);
	}
	return x;
}
