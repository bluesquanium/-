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

ll T, N, P, K, X, Y, ans, temp;
string s;
vector<ll> m;
ll cnt0[100000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> P >> K;
		P--;
		cin >> s;
		cin >> X >> Y;

		ans = LINF;
		for (ll i = 0; i < K; i++) {
			cnt0[i] = 0;
			for (ll j = i + P; j < N; j += K) {
				if (s[j] == '0') {
					cnt0[i]++;
				}
			}
		}

		for (ll i = 0; i < N - P; i++) {
			ll k = i % K;
			ans = min(ans, Y * i + cnt0[k] * X);
			if (s[i + P] == '0') {
				cnt0[k]--;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
