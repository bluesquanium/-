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

ll T, N, ans;
vector<ll> m;
ll pow2[32];
ll cnt[32];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	pow2[0] = 1;
	for (ll i = 1; i < 32; i++) {
		pow2[i] = pow2[i - 1] * 2;
	}

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		for (ll i = 0; i < 32; i++) {
			cnt[i] = 0;
		}
		ans = 0;
		cin >> N;
		N--;

		ll joker = 0;
		ll cur = 1;
		while (N) {
			if (N - pow2[cur] >= 0) {
				cnt[cur]++;
				N -= pow2[cur];

				cur++;
			}
			else {
				joker = N;
				break;
			}
		}

		for (ll i = 0; i < 32; i++) {
			ans += cnt[i];
		}
		if (joker) ans++;
		cout << ans << '\n';
		
		if (joker == 1) {
			cout << 0 << ' ';
			joker = 0;
		}
		if (cnt[0]) {
			for (ll i = 0; i < cnt[0]; i++) {
				cout << 0 << ' ';
			}
		}
		ll plus_alpha = 0;
		for (ll i = 1; i < 32; i++) {
			if (cnt[i] == 0) {
				break;
			}

			cout << pow2[i - 1] - plus_alpha << ' ';
			plus_alpha = 0;
			for (ll j = 1; j < cnt[i]; j++) {
				cout << 0 << ' ';
			}
			if (joker != 0 && joker <= pow2[i + 1]) {
				if (joker == pow2[i]) {
					cout << 0 << ' ';
					joker = 0;
				}
				else {
					cout << joker - pow2[i] << ' ';
					plus_alpha = joker - pow2[i];
					joker = 0;
				}
			}
		}
		cout << '\n';
	}

	return 0;
}
