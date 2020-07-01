#include <iostream>
#include <cmath>
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

ll T, ans;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> s;

		ll sum = 0, cur = 0;
		for (; cur < s.size(); cur++) {
			if (s[cur] == '+') {
				sum++;
			}
			else {
				sum--;
			}

			if (sum == -1) {
				sum = 0;
				ans += cur + 1;
			}
		}
		ans += cur;

		cout << ans << '\n';
	}

	return 0;
}
