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

ll T, N, X, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> X;
		m.clear(); m.resize(N);
		ll lastDefect = -1;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (i > 0 && m[i - 1] > m[i]) {
				lastDefect = i - 1;
			}
		}

		ans = 0;
		if (lastDefect != -1) {
			for (ll i = 0; i <= lastDefect; i++) {
				if (m[i] > X) {
					swap(m[i], X);
					ans++;
				}
				
				if (i != 0 && m[i - 1] > m[i]) {
					ans = -1;
					break;
				}
			}
			if (ans != -1) {
				if (m[lastDefect] > m[lastDefect + 1]) {
					ans = -1;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
