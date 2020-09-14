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

#define MAX 1024
ll ftree[MAX + 1][MAX + 1];

ll N, M, cmd;
ll m[MAX + 1][MAX + 1];

void fInit(ll N) {
	memset(ftree, 0, sizeof(ll) * 2 * (N + 1));
}

ll fCalculate(ll ft, ll idx) {
	ll ret = 0;
	while (idx > 0) {
		ret += ftree[ft][idx];
		idx -= idx & (-idx);
	}

	return ret;
}

ll fCalculateRange(ll ft, ll a, ll b) {
	ll ret = 0;
	while (b > 0) {
		ret += ftree[ft][b];
		b -= b & (-b);
	}
	a--;
	while (a > 0) {
		ret -= ftree[ft][a];
		a -= a & (-a);
	}

	return ret;
}

void fUpdate(ll ft, ll idx, ll before, ll after) {
	ll delta = after - before;

	while (idx <= N) {
		ftree[ft][idx] += delta;
		idx += idx & (-idx);
	}
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {
			cin >> m[i][j];
			fUpdate(i, j, 0, m[i][j]);
		}
	}

	for (ll i = 0; i < M; i++) {
		cin >> cmd;
		if (cmd == 0) {
			ll x, y, c;
			cin >> x >> y >> c;

			fUpdate(x, y, m[x][y], c);
		}
		else { // sum
			ll x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;

			ll sum = 0;
			for (ll i = x1; i <= x2; i++) {
				sum += fCalculateRange(i, y1, y2);
			}
			cout << sum << '\n';
		}
	}

	return 0;
}

