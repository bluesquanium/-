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
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll T, N, K, ans, temp;
vector<ll> m;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> K;
		cin >> s;

		ans = 0;
		ll cnt = 0;
		for (ll i = 0; i < N; i++) {
			if (s[i] != 'L') {
				if (cnt == 0) {
					cnt = 1;
				}
				else {
					cnt += 2;
				}
			}
			else {
				ans += cnt;
				cnt = 0;
			}
		}
		ans += cnt;

		if (ans) {
			deque<ll> temp_segs;
			vector<ll> segs;
			cnt = 0;
			for (ll i = 0; i < N; i++) {
				if (s[i] == 'L') {
					cnt++;
				}
				else {
					if (cnt != 0) {
						temp_segs.push_back(cnt);
						cnt = 0;
					}
				}
			}
			if (cnt) {
				temp_segs.push_back(cnt);
				cnt = 0;
			}

			ll last_segs = 0;
			if (s[0] == 'L') {
				last_segs += temp_segs.front();
				temp_segs.pop_front();
			}
			if (s[N - 1] == 'L') {
				last_segs += temp_segs.back();
				temp_segs.pop_back();
			}

			for (ll i = 0; i < temp_segs.size(); i++) {
				segs.push_back(temp_segs[i]);
			}

			sort(segs.rbegin(), segs.rend());
			while (!segs.empty()) {
				ll cur = segs.back(); segs.pop_back();

				if (cur <= K) {
					K -= cur;
					ans += cur * 2 + 1;
				}
				else {
					ans += K * 2;
					K = 0;
					break;
				}
			}

			if (K != 0) {
				if (ans) {
					ans += min(last_segs, K) * 2;
				}
				else {
					ans = min(last_segs, K) * 2 - 1;
				}
			}
		}
		else {
			ans = min(N, K) * 2 - 1;
			if (ans < 0) {
				ans = 0;
			}
		}
		

		cout << ans << '\n';
	}

	return 0;
}
