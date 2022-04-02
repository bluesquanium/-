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
		cin >> N;
		string s;
		cin >> s;
		ll start = s[0];
		ll point = -1;
		ll y1, x1, y2, x2;

		ll path = 1;
		pll cur = { 0, 0 };
		for (ll i = 0; i < s.size(); i++) {
			path++;
			if (s[i] == 'R') {
				cur.second++;
			}
			else {
				cur.first++;
			}
			if (s[i] != start && point == -1) {
				point = i;
				y1 = cur.first;
				x1 = cur.second;
				if (s[i] == 'R') {
					x1--;
				}
				else {
					y1--;
				}
			}
		}
		y2 = cur.first;
		x2 = cur.second;

		if (point == -1) {
			cout << N << '\n';
		}
		else {
			ll width = (y2 - y1 + 1) * (x2 - x1 + 1);
			ans = N * N - width - point * N + path;

			cout << ans << '\n';
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
