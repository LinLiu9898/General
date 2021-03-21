const int N = 5e6;

bitset<N> isprime;
vector<int> primes;

void sieve() {
	isprime.set();
	isprime[0] = isprime[1] = 0;
	for(int i = 4; i < N; i += 2) {
		isprime[i] = 0;
	}
	for(int i = 3; i * i < N; i += 2) {
		if(!isprime[i]) {
			continue;
		}
		for(int j = i * i; j < N; j += i * 2) {
			isprime[j] = 0;
		}
	}
	for(int i = 2; i < N; ++i) {
		if(isprime[i]) {
			primes.pb(i);
		}
	}
}
