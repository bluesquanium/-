#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

#define MAXBIT 300001
class Bit {
public:
	ll tree[MAXBIT];

	void add(ll x, ll v) {
		for (ll i = x; i < MAXBIT; i += i & -i) {
			tree[i] += v;
		}
	}

	ll query(ll x) {
		ll ret = 0;
		for (ll i = x; i; i -= i & -i) {
			ret += tree[i];
		}
		return ret;
	}
} bit;

ll N, Q, temp;
vector<ll> m, ans;
vector< vector<pll> > queries;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> Q;
	m.resize(N + 1);
	queries.resize(N + 1);
	ans.resize(Q);
	for (ll i = 1; i <= N; i++) {
		cin >> m[i];
		m[i] = i - m[i];
		if (m[i] < 0) {
			m[i] = LINF;
		}
	}
	for (ll q = 0; q < Q; q++) {
		ll x, y;
		cin >> x >> y;
		queries[N - y].push_back({ x + 1, q });
	}

	for (ll i = 1; i <= N; i++) {
		ll s = 0, e = i;
		while (s != e) {
			ll mid = (s + e + 1) / 2;
			if (bit.query(mid) >= m[i]) {
				s = mid;
			}
			else {
				e = mid - 1;
			}
		}
		bit.add(1, 1);
		bit.add(s + 1, -1);

		for (pll q : queries[i]) {
			ans[q.second] = bit.query(q.first);
		}
	}

	for (ll i = 0; i < Q; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}
