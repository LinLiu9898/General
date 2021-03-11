vector<bool> prime;
vector<int> primes;

void sieve(int n) {
	prime.assign(n + 1, true);
	prime[0] = prime[1] = false;
	primes.clear();
	for(int i = 2; i * i <= n; ++i) {
		if(prime[i]) {
			for(int j = i * i; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}
	for(int i = 0; i < si(prime); ++i) {
		if(prime[i]) {
			primes.pb(i);
		}
	}
}
