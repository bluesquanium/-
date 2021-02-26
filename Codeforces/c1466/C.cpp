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

ll T, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		string s;
		cin >> s;
		ans = 0;
		for (ll i = 1; i < s.size(); i++) {
			if (s[i - 1] == s[i] || (i > 1 && s[i - 2] == s[i])) {
				ll duplicated[5] = { 0 };
				for (ll j = i - 2; j <= i + 2; j++) {
					if (j < 0 || j == i) {
						continue;
					}
					if (s[j] - 'a' < 5) {
						duplicated[s[j] - 'a'] = 1;
					}
				}
				for (ll j = 0; j < 5; j++) {
					if (duplicated[j] == 0) {
						s[i] = 'a' + j;
						break;
					}
				}
				ans++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
