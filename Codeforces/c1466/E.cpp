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

#define MOD 1000000007

ll T, N, M, ans, temp;
vector<ll> m;
ll digitCnt[60];
ll mulVal[60];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	ll val = 1;
	for (ll i = 0; i < 60; i++) {
		mulVal[i] = val;
		val *= 2;
		val %= MOD;
	}

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		ll sum = 0;
		for (ll i = 0; i < 60; i++) {
			digitCnt[i] = 0;
		}

		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			sum += m[i];
			sum %= MOD;

			ll num = m[i];
			ll j = 0;
			while (num) {
				digitCnt[j] += num % 2;
				num /= 2;
				j++;
			}
		}

		for (ll i = 0; i < N; i++) {
			ll digitVal = 0;
			ll num = m[i];
			ll j = 0;
			while (num) {
				if (num % 2) {
					digitVal += digitCnt[j] * mulVal[j];
					digitVal %= MOD;
				}
				num /= 2;
				j++;
			}

			// Right
			ll r = sum + (m[i] % MOD) * N;
			r %= MOD;
			r += MOD - digitVal;
			r %= MOD;

			// Left
			ll l = digitVal;

			ans += (l * r) % MOD;
			ans %= MOD;
		}

		cout << ans << '\n';
	}

	return 0;
}
