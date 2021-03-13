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

ll T, N, U, V, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> U >> V;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}
		bool allSame = true;
		for (ll i = 1; i < N; i++) {
			if (m[i] != m[0]) {
				allSame = false;
				break;
			}
		}

		if (allSame == false) {
			ll ans = -1;
			for (ll i = 1; i < N; i++) {
				if (abs(m[i - 1] - m[i]) > 1) {
					ans = 0;
					break;
				}
			}
			if (ans == -1) {
				ans = min(U, V);
			}
			cout << ans << '\n';
		}
		else {
			ll ans = min(V + V, U + V);
			cout << ans << '\n';
		}
	}

	return 0;
}
