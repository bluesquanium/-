#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll K, N, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> K >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}

	for (ll n = 0; n < N; n++) {
		ans = 0;
		if (K <= m[n]*(m[n] + 1) / 2) {
			for (ll i = 1; i <= m[n]; i++) {
				if (K <= i * (i + 1) / 2) {
					ans = i;
					break;
				}
			}
		}
		else {
			ll num = m[n] * (m[n] + 1) / 2;
			ans = m[n];
			for (ll i = 1; i < 100000; i++) {
				if (K < num + i * (i + 1) - i + m[n] * (2*i - 1)) {
					ans++;
					num += m[n];
					ans += (2 * (i-1) - 1);
					num += (i - 1) * i - (i-1) + m[n] * (2 * (i-1) - 1);
					if (i == 1) {
						num += m[n];
						ans++;
					}
					ans += ((K - num) + (m[n] + i - 1 - 1)) / (m[n] + i-1);

					break;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
