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
#define NUM_ALPHA 26
using namespace std;

ll T, N, K;
vector<ll> m;
string s, ans;
ll cnt[NUM_ALPHA];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = "";
		for (ll i = 0; i < NUM_ALPHA; i++) {
			cnt[i] = 0;
		}

		cin >> N >> K;
		cin >> s;
		for (ll i = 0; i < s.size(); i++) {
			cnt[s[i] - 'a']++;
		}

		ll sum = 0, first_alpha = 0, mode;
		for (ll i = 0; i < NUM_ALPHA; i++) {
			if (cnt[i]) {
				if (cnt[i] < K) {
					mode = 1;
				}
				else {
					mode = 2;
					first_alpha = i;
				}
				break;
			}
		}

		if (mode == 1) {
			ll sum = 0;
			for (ll i = 0; i < NUM_ALPHA; i++) {
				sum += cnt[i];
				if (sum >= K) {
					ans.push_back('a' + i);
					cout << ans << '\n';
					break;
				}
			}
		}
		else {
			ans.push_back(first_alpha + 'a');
			ll remain_kind = 0;
			
			if (cnt[first_alpha] - K > 0) {
				remain_kind++;
			}
			for (ll i = first_alpha + 1; i < NUM_ALPHA; i++) {
				if (cnt[i]) {
					remain_kind++;
				}
			}

			if (remain_kind == 1) {
				if (cnt[first_alpha] - K > 0) {
					cnt[first_alpha] -= K;
					for (ll j = 0; j < cnt[first_alpha] / K; j++) {
						ans.push_back(first_alpha + 'a');
					}
					if (cnt[first_alpha] % K) {
						ans.push_back(first_alpha + 'a');
					}
				}
				else {
					for (ll i = first_alpha + 1; i < NUM_ALPHA; i++) {
						if (cnt[i]) {
							for (ll j = 0; j < cnt[i] / K; j++) {
								ans.push_back(i + 'a');
							}
							if (cnt[i] % K) {
								ans.push_back(i + 'a');
							}
							//break;
						}
					}
				}
			}
			else if (remain_kind > 1) {
				for (ll i = K; i < cnt[first_alpha]; i++) {
					ans.push_back(first_alpha + 'a');
				}
				for (ll i = first_alpha + 1; i < NUM_ALPHA; i++) {
					for (ll j = 0; j < cnt[i]; j++) {
						ans.push_back(i + 'a');
					}
				}
			}

			cout << ans << '\n';
		}
	}

	return 0;
}
