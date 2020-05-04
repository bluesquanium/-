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

#define NUM_ALPHA 26

ll T, N, K, ans;
ll dict[NUM_ALPHA];
string s;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N >> K;
		cin >> s;

		for (ll i = 0; i < (K + 1) / 2; i++) {
			ll cnt = 0;
			memset(dict, 0, sizeof(ll) * NUM_ALPHA);
			for (ll j = 0; j < N; j += K) {
				dict[s[j + i] - 'a']++;
				cnt++;
				if (j + i != j + K - 1 - i) {
					dict[s[j + K - 1 - i] - 'a']++;
					cnt++;
				}
			}

			ll maxi = 0;
			for (ll j = 0; j < NUM_ALPHA; j++) {
				maxi = max(maxi, dict[j]);
			}

			ans += cnt - maxi;
		}

		cout << ans << '\n';
	}

	return 0;
}
