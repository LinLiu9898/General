#include "bits/extc++.h"
using namespace std;

#define int int64_t
#define trav(i, a) for(auto& i: a)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define si(a) ((int)(a).size())
#define ins insert
#define pb push_back
#define f first
#define s second

const int MOD = 1e9 + 7;
const int INF = 1e18;
const string nl = "\n";

#define ook order_of_key
#define fbo find_by_order

template <class T, class H, class Comp = std::less<T>>
using omap = __gnu_pbds::tree<T, H, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename K, typename Comp = std::less<K>>
using oset = omap<K, __gnu_pbds::null_type, Comp>;


int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	trav(i, a) {
		cin >> i;
	}
	vector<int> last(n + 1, -1);
	oset<int> hld;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += si(hld) - hld.ook(last[a[i]] + 1);
		if(last[a[i]] != -1) {
			hld.erase(last[a[i]]);
		}
		hld.ins(i);
		last[a[i]] = i;
	}
	cout << ans << nl;
}
