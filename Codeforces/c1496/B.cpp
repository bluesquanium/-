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

ll T, N, K, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> K;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}
		sort(m.begin(), m.end());

		ans = N;
		if (K != 0) {
			ll mexi = 0;
			for (ll i = 0; i < N; i++) {
				if (m[i] != mexi) {
					break;
				}
				mexi++;
			}
			ll maxi = m[N - 1];
			if (mexi > maxi) { // infinite
				ans += K;
			}
			else {
				ll target = (maxi + mexi + 1) / 2;
				ll plusV = 1;
				for (ll i = 0; i < N; i++) {
					if (m[i] == target) {
						plusV = 0;
						break;
					}
				}
				ans += plusV;
			}
		}
		
		cout << ans << '\n';
	}

	return 0;
}
