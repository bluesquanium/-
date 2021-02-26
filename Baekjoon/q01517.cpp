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
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

#define MAXBIT 500001
class Bit {
public:
	ll tree[MAXBIT];

	void init() {
		for (ll i = 0; i < MAXBIT; i++) tree[i] = 0;
	}

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

ll N, M, ans, temp;
vector<pll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> temp;
		m[i] = { temp, i + 1 };
	}
	sort(m.rbegin(), m.rend());

	bit.init();
	for (ll i = 0; i < N; i++) {
		ans += bit.query(m[i].second) - bit.query(0) + N - i - m[i].second;

		bit.add(m[i].second, 1);
	}

	cout << ans;

	return 0;
}
