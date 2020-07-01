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

ll T, A, B, C, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> A >> B >> C;
		ll ans1 = -1, ans2 = -1;
		if (A < C) {
			ans1 = 1;
		}
		if (A * B > C) {
			ans2 = B;
		}

		cout << ans1 << ' ' << ans2 << '\n';
	}

	return 0;
}
