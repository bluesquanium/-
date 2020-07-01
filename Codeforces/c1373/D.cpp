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

ll T, N, M, ans;
vector<ll> m;
ll mem[200000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			mem[i] = 0;
		}

		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (i % 2 == 0) {
				ans += m[i];
			}
		}
		for (ll i = 0; i < N; i++) {
			if (i % 2 == 0) {
				if (i + 1 < N) {
					mem[i] = m[i + 1] - m[i];
				}
			}
			else {
				if (i + 1 < N) {
					mem[i] = m[i] - m[i + 1];
				}
			}
		}

		ll maxi = 0;
		ll sum = 0;
		for (ll i = 0; i < N; i += 2) {
			sum += mem[i];
			if (sum < 0) {
				sum = 0;
			}
			maxi = max(sum, maxi);
		}
		sum = 0;
		for (ll i = 1; i < N; i += 2) {
			sum += mem[i];
			if (sum < 0) {
				sum = 0;
			}
			maxi = max(sum, maxi);
		}

		cout << ans + maxi << '\n';
	}

	return 0;
}
