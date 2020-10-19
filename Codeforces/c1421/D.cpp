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

ll T, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ll x, y;
		ll c[6];
		cin >> x >> y;
		for (ll i = 0; i < 6; i++) {
			cin >> c[i];
		}
		for (ll i = 0; i < 6; i++) {
			c[i] = min(c[i], c[(i + 5) % 6] + c[(i + 1) % 6]);
		}

		ans = 0;
		if (x > 0 && y > 0) {
			ll t = min(x, y);
			ans += c[0] * t;
			x -= t;
			y -= t;
		}
		else if(x < 0 && y < 0) {
			ll t = -max(x, y);
			ans += c[3] * t;
			x += t;
			y += t;
		}
		if (x > 0) {
			ans += c[5] * x;
		}
		else {
			ans += c[2] * (-x);
		}
		if (y > 0) {
			ans += c[1] * y;
		}
		else {
			ans += c[4] * (-y);
		}
		cout << ans << '\n';
	}

	return 0;
}
