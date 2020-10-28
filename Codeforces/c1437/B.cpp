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

ll T, N, M, ans, temp;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		ll ans_0 = 0;
		cin >> N;
		cin >> s;

		ll cnt = 0;
		for (ll i = 0; i < N; i++) {
			if (s[i] == '1') {
				cnt++;
			}
			else {
				if (cnt > 1) {
					ans += cnt - 1;
				}
				cnt = 0;
			}
		}
		if (cnt > 1) {
			ans += cnt - 1;
		}

		cnt = 0;
		for (ll i = 0; i < N; i++) {
			if (s[i] == '0') {
				cnt++;
			}
			else {
				if (cnt > 1) {
					ans_0 += cnt - 1;
				}
				cnt = 0;
			}
		}
		if (cnt > 1) {
			ans_0 += cnt - 1;
		}

		cout << max(ans, ans_0) << '\n';
	}

	return 0;
}
