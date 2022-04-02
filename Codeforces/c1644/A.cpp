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

ll T, N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		string s;
		cin >> s;
		ll keys[3] = { 0, 0, 0 };
		ans = 1;
		for (ll i = 0; i < 6; i++) {
			if (s[i] == 'r') {
				keys[0] = 1;
			} else if (s[i] == 'g') {
				keys[1] = 1;
			} else if (s[i] == 'b') {
				keys[2] = 1;
			} else if (s[i] == 'R') {
				if (keys[0] != 1) {
					ans = 0;
					break;
				}
			} else if (s[i] == 'G') {
				if (keys[1] != 1) {
					ans = 0;
					break;
				}
			} else if (s[i] == 'B') {
				if (keys[2] != 1) {
					ans = 0;
					break;
				}
			}
		}

		if (ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
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
