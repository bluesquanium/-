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

#define MAXBIT 1000001
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

ll N, M, K, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> K;
	m.resize(N + 1);
	for (ll i = 1; i <= N; i++) {
		cin >> m[i];
		bit.add(i, m[i]);
	}
	for (ll i = 0; i < M + K; i++) {
		ll cmd, b, c, d;
		cin >> cmd;
		if (cmd == 1) {
			cin >> b >> c >> d;
			for (ll j = b; j <= c; j++) {
				bit.add(j, d);
			}
		}
		else {
			cin >> b >> c;
			ll sum = bit.query(c) - bit.query(b - 1);
			cout << sum << '\n';
		}
	}

	return 0;
}
