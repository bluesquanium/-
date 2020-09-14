// °³³ä: https://www.acmicpc.net/blog/view/21

#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;


#define FTMAX 1024

ll N, M, cmd;
ll m[FTMAX + 1];

ll ftree[FTMAX + 1];

void ftInit(ll n) {
	memset(ftree, 0, sizeof(ll) * (n + 1));
}

ll ftCalculate(ll idx) {
	ll ret = 0;
	while (idx > 0) {
		ret += ftree[idx];
		idx -= idx & (-idx);
	}

	return ret;
}

ll ftCalculateRange(ll a, ll b) {
	ll ret = 0;
	while (b > 0) {
		ret += ftree[b];
		b -= b & (-b);
	}
	a--;
	while (a > 0) {
		ret -= ftree[a];
		a -= a & (-a);
	}

	return ret;
}

void ftUpdate(ll idx, ll before, ll after) {
	ll delta = after - before;

	while (idx <= N) {
		ftree[idx] += delta;
		idx += idx & (-idx);
	}
}

// ¿¹½Ã 
int main(void) {
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (ll i = 1; i <= N; i++) {
		cin >> m[i];
		ftUpdate(i, 0, m[i]);
	}

	for (ll i = 0; i < M; i++) {
		cin >> cmd;
		if (cmd == 0) { // update
			ll x, c;
			cin >> x >> c;

			ftUpdate(x, m[x], c);
		}
		else { // sum
			ll x1, x2;
			cin >> x1 >> x2;

			ll sum = 0;
			sum += ftCalculateRange(x1, x2);
			cout << sum << '\n';
		}
	}

	return 0;
}

