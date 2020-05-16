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

ll T, N, K, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N >> K;

		if (N % 2 == 0) {
			ans = N + 2 * K;
		}
		else {
			for (ll i = 3; i <= 1000000; i++) {
				if (N % i == 0) {
					ans = N + i;
					break;
				}
			}
			ans += 2 * (K - 1);
		}

		cout << ans << '\n';
	}

	return 0;
}
