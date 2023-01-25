#include "bits/stdc++.h"
using namespace std;

#define int int64_t
#define trav(i, a) for(auto& i: a)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define si(a) ((int)(a).size())
#define ins insert
#define pb push_back
#define mp make_pair
#define f first
#define s second

const int MOD = 1e9 + 7;
const int INF = 1e18;
const string nl = "\n";

vector<int> hld(5e6 + 10, -1);
vector<int> dist(5e6 + 10, 0);
const int maximum = 5e6 + 10;
int cur_generated;
vector<bool> isprime;
vector<int> primes, spf;
bool is_built_sieve = false;

void sieve() {
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


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	trav(i, a) {
		cin >> i;
	}
	int curmi = INF;
	for(int i = 0; i < n; ++i) {
		if(isprime[a[i]]) {
			curmi = 1;
			break;
		}
		if(a[i] % 4 == 0) {
			curmi = min(curmi, a[i] / 4 + 1);
		} else if(a[i] % 2 == 0) {
			curmi = min(curmi, (a[i] + 2) / 4);
		} else {
			curmi = min(curmi, dist[a[i]]);
		}
	}
	for(int i = 0; i < n; ++i) {
		if(isprime[a[i]]) {
			cout << "Farmer John" << nl;
			break;
		}
		if(a[i] % 4 == 0) {
			if(curmi == a[i] / 4 + 1) {
				cout << "Farmer Nhoj" << nl;
				break;
			}
		} else if(a[i] % 2 == 0) {
			if(curmi == (a[i] + 2) / 4) {
				cout << "Farmer John" << nl;
				break;
			}
		} else {
			if(curmi == dist[a[i]] ) {
				cout << "Farmer John" << nl;
				break;
			}
		}
	}
	//cout << "Farmer John" << nl;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	sieve();
	hld[0] = 0;
	hld[1] = 1;
	dist[0] = 1;
	dist[1] = 1;
	for(int i = 0; i < si(primes); ++i) {
		hld[primes[i]] = 1; // 1 means farmer john wins
		dist[primes[i]] = 1;
	}
	for(int i = 4; i < si(hld); ++i) {
		if(i % 2 == 0) {
			continue;
		}
		for(int j = 4; j < maximum; j += 4) {
			if(i >= j && isprime[i - j]) {
				dist[i] = (j / 4) + 1;
				break;
			}
		}
	}
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}
