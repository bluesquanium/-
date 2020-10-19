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

ll T, N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		ans = 0;
		if (x1 != x2 && y1 != y2) {
			ans = 2;
		}
		ans += abs(x1 - x2) + abs(y1 - y2);

		cout << ans << '\n';
	}

	return 0;
}
