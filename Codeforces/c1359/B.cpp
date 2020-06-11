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

ll T, N, M, X, Y, ans;
vector<string> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N >> M >> X >> Y;
		Y = min(Y, X * 2);
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			ll cnt = 0;
			for (ll j = 0; j < m[i].size(); j++) {
				if (m[i][j] == '.') {
					cnt++;
				}
				else {
					ans += cnt / 2 * Y + (cnt % 2) * X;
					cnt = 0;
				}
			}
			ans += cnt / 2 * Y + (cnt % 2) * X;
		}

		cout << ans << '\n';
	}

	return 0;
}
