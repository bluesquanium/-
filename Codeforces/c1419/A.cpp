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

ll T, N, M, ans, temp;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		cin >> s;
		ll i;
		if (s.size() % 2 == 0) { // even
			i = 1;
			ans = 1;
		}
		else { // odd
			i = 0;
			ans = 2;
		}
		for (; i < s.size(); i += 2) {
			if (s.size() % 2 == 0) { // even
				if (s[i] % 2 == 0) {
					ans = 2;
				}
			}
			else {
				if (s[i] % 2) {
					ans = 1;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
