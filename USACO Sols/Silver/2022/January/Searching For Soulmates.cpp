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

void solve() {
    int a, b;
    cin >> a >> b;
    if(a == 1 && b == 1) {
        cout << 0 << nl;
        return;
    }
    auto find = [&](int x, int y) -> int {
        int cnt = 0;
        while(x <= y) {
            x *= 2;
            ++cnt;
        }
        if(cnt > 0) {
            x /= 2;
            --cnt;
        }
        if(x == y) {
            return cnt;
        }
        int curans = 0;
        int hld = y - x;
        for(int i = 63; i >= 0; --i) {
            if(hld & (1LL << i)) {
                if((1LL << i) < (1LL << cnt)) {
                    ++curans;
                } else {
                    curans += (1LL << (i - cnt));
				}
			}
		}
		return curans + cnt;
	};
	int ans = INF;
	int cur = 0;
	while(a != 1) {
		if(a <= b) {
			ans = min(ans, find(a, b) + cur);
		}
		if(a & 1) {
			++a;
			++cur;
		}
		a /= 2;
		++cur;
		if(a <= b) {
			ans = min(ans, find(a, b) + cur);
		}
	}
	cout << ans << nl;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}
