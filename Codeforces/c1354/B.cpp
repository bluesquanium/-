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

ll T, N, M, ans;
ll p1, p2, p3;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = INF;
		p1 = p2 = p3 = -1;
		cin >> s;
		for (ll i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				p1 = i;
			}
			else if (s[i] == '2') {
				p2 = i;
			}
			else {
				p3 = i;
			}
			if (p1 != -1 && p2 != -1 && p3 != -1) {
				ll left = min(p1, min(p2, p3)), right = max(p1, max(p2, p3));
				ans = min(ans, right - left + 1);
			}
		}

		if (ans == INF) {
			ans = 0;
		}
		cout << ans << '\n';
	}

	return 0;
}
