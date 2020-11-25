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

ll T, A, B, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		string s;
		cin >> A >> B;
		cin >> s;

		ll startIdx = -1;
		for (ll i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				startIdx = i;
				break;
			}
		}

		ans = 0;
		if (startIdx != -1) {
			ans = A;
			ll current = 1, zeroCnt = 0;
			for (ll i = startIdx; i < s.size(); i++) {
				if (s[i] == '1') {
					if (current == 0) {
						if (A > zeroCnt * B) {
							ans += zeroCnt * B;
						}
						else {
							ans += A;
						}

						current = 1;
						zeroCnt = 0;
					}
				}
				else {
					if (current == 1) {
						current = 0;
						zeroCnt = 1;
					}
					else {
						zeroCnt++;
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
