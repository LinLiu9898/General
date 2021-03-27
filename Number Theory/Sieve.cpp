int cur_generated;
vector<bool> isprime;
vector<int> primes, spf;

void sieve(int maximum) {
	cur_generated = maximum;
	isprime.assign(maximum + 10, true);
	isprime[0] = isprime[1] = false;
	spf.resize(maximum + 10);
	iota(all(spf), 0LL);
	for(int i = 2; i * i < maximum; ++i) {
		if(isprime[i]) {
			spf[i] = i;
			for(int j = i * i; j < maximum; j += i) {
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
}

vector<int> factor(int x) {
	assert(x > 0 && cur_generated >= x);
	vector<int> res;
	while(x > 1) {
		res.pb(spf[x]);
		x /= spf[x];
	}
	return res;
}
