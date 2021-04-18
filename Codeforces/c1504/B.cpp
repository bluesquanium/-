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
		string s1, s2;
		cin >> N;
		cin >> s1;
		cin >> s2;

		ans = 1;

		ll base = 0;
		ll cnt0 = 0, cnt1 = 0;
		for (ll i = 0; i < N; i++) {
			if (s1[i] == '0') {
				cnt0++;
			}
			else {
				cnt1++;
			}

			if (cnt0 == cnt1) {
				ll isSame = 0;
				if (s1[base] == s2[base]) {
					isSame = 1;
				}

				for (ll j = base; j <= i; j++) {
					if (isSame == 1) {
						if (s1[j] != s2[j]) {
							ans = 0;
							break;
						}
					}
					else {
						if (s1[j] == s2[j]) {
							ans = 0;
							break;
						}
					}
				}

				if (ans == 0) {
					break;
				}
				base = i + 1;
			}
		}

		for (ll i = base; i < N; i++) {
			if (s1[i] != s2[i]) {
				ans = 0;
				break;
			}
		}

		if (ans == 1) {
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
