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

#define MAXBIT 100001
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

ll N, Q, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> Q;
	m.resize(N + 1);
	for (ll i = 1; i <= N; i++) {
		cin >> m[i];
		bit.add(i, m[i]);
	}

	for (ll q = 0; q < Q; q++) {
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) {
			ll t = x;
			x = y;
			y = t;
		}
		cout << bit.query(y) - bit.query(x - 1) << '\n';
		bit.add(a, b - m[a]);
		m[a] = b;
	}

	return 0;
}
