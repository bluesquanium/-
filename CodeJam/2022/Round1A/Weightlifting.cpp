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

ll T, E, W, ans, temp;
vector<ll> m;

ll POW = 3;
ll to3[20000];

#define pow39 19683 // 3^9
ll mem[2][20000];

ll es[100][100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	for (ll t = 1; t <= T; t++) {

		cin >> E >> W;
		POW = W;
		ll idx = 0;
		ll digit[9] = { 0 };
		ll check = 1;
		while (check) {
			ll sum = 0;
			for (ll i = 0; i < W * 3; i++) {
				sum += digit[i];
				sum *= POW;
			}
			to3[idx++] = sum;

			for (ll i = W * 3 - 1; i >= 0; i--) {
				digit[i]++;
				if (digit[i] == POW) {
					if (i == 0) {
						check = 0;
					}
					digit[i] = 0;
				}
				else {
					break;
				}
			}
		}

		for (ll i = 0; i < E; i++) {
			for (ll j = 0; j < W; j++) {
				cin >> es[i][j];
			}
		}

		for (ll i = 0; i < idx; i++) {
			mem[1][i] = INF;
		}


		ll e = 0;
		ll wPrevSum = 0;
		for (ll w = 0; w < W; w++) {
			wPrevSum += es[e][w];
		}

		for (ll i = 0; i < idx; i++) {
			ll idx3 = to3[i];
			vector<ll> cnt;
			cnt.resize(W);
			for (ll w = 0; w < W; w++) {
				cnt[w] = es[e][w];
			}
			ll check = 1;
			temp = idx3;
			for (ll j = 0; j < wPrevSum; j++) {
				ll cur = temp % POW;
				temp /= POW;
				cnt[cur]--;
				if (cnt[cur] < 0) {
					check = 0;
					break;
				}
			}

			if (check == 0) {
				continue;
			}

			mem[1][i] = wPrevSum;
		}

		for (ll e = 1; e < E; e++) {
			for (ll i = 0; i < idx; i++) {
				mem[0][i] = mem[1][i];
				mem[1][i] = INF;
			}

			ll wSum = 0;
			for (ll w = 0; w < W; w++) {
				wSum += es[e][w];
			}
			for (ll i = 0; i < idx; i++) {
				ll idx3 = to3[i];
				vector<ll> cnt;
				cnt.resize(W);
				for (ll w = 0; w < W; w++) {
					cnt[w] = es[e][w];
				}
				ll check = 1;
				temp = idx3;
				for (ll j = 0; j < wSum; j++) {
					ll cur = temp % POW;
					temp /= POW;
					cnt[cur]--;
					if (cnt[cur] < 0) {
						check = 0;
						break;
					}
				}

				if (check == 0) {
					continue;
				}

				for (ll i2 = 0; i2 < idx; i2++) {
					if (mem[0][i2] == INF) continue;

					ll idx3_2 = to3[i2];
					ll mini = min(wSum, wPrevSum);
					ll offset = 0;

					ll cur1 = idx3;
					ll cur2 = idx3_2;
					for (ll j = 0; j < mini; j++) {
						if ((cur1 % POW) != (cur2 % POW)) {
							offset = j;
							break;
						}
						cur1 /= POW;
						cur2 /= POW;

						offset = j + 1;
					}

					ll cnt = abs(wSum - wPrevSum) + abs(mini - offset) * 2;

					mem[1][i] = min(mem[1][i], mem[0][i2] + cnt);
				}
			}

			wPrevSum = wSum;

			ll ans2 = INF;
			for (ll i = 0; i < idx; i++) {
				ans2 = min(ans2, mem[1][i] + wPrevSum);
			}
			ans2 = ans2;
		}

		ans = INF;
		for (ll i = 0; i < idx; i++) {
			ans = min(ans, mem[1][i] + wPrevSum);
		}

		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}

/*
0. Enough array size? Enough array size? Integer overflow?

1. Think TWICE, Code ONCE!
Are there any counterexamples to your algo?

2. Be careful about the BOUNDARIES!
N=1? P=1? Something about 0?

3. Do not make STUPID MISTAKES!
Time complexity? Memory usage? Precision error?

4. Be careful to wrong variable.
*/
