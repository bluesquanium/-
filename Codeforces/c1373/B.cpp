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
		cin >> s;
		ll cnt0 = 0, cnt1 = 0;
		for (ll i = 0; i < s.size(); i++) {
			if (s[i] == '0') {
				cnt0++;
			}
			else {
				cnt1++;
			}
		}

		ans = min(cnt0, cnt1);

		if (ans % 2 == 0) {
			cout << "NET\n";
		}
		else { // odd
			cout << "DA\n";
		}
	}

	return 0;
}
