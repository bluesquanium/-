#include <iostream>
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

ll T, N, P, K, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N >> P >> K;
		m.clear(); m.resize(N + 1);
		for (ll i = 1; i <= N; i++) {
			cin >> m[i];
		}
		sort(m.begin(), m.end());

		ll base = 0;
		for (ll i = 0; i < K; i++) {
			base += m[i];
			if (base <= P) {
				ll sum = base, cnt = i;
				for (ll j = i + K; j <= N; j += K) {
					sum += m[j];
					if (sum > P) {
						break;
					}
					cnt += K;
				}

				ans = max(ans, cnt);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
