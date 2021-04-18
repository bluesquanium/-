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
		ans = 0;
		for (ll i = 0; i < s.size(); i++) {
			if (s[i] != 'a') {
				ans = 1;
			}
		}

		if (ans == 0) {
			cout << "NO\n";
		}
		else {
			ll insertPoint = -1;
			for (ll i = 0; i < s.size(); i++) {
				if (s[i] != 'a') {
					insertPoint = s.size() - i;
					break;
				}
			}

			cout << "YES\n";
			for (ll i = 0; i < insertPoint; i++) {
				cout << s[i];
			}
			cout << 'a';
			for (ll i = insertPoint; i < s.size(); i++) {
				cout << s[i];
			}
			cout << '\n';
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
