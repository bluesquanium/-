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
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		string s;
		cin >> s;
		ans = s.size();
		ll cnt[2] = { 0 };
		for (ll i = 0; i < s.size(); i++) {
			if (s[i] == 'A') {
				cnt[0]++;
			}
			else {
				if (cnt[0]) {
					cnt[0]--;
					ans -= 2;
				}
				else if (cnt[1]) {
					cnt[1]--;
					ans -= 2;
				}
				else {
					cnt[1]++;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
