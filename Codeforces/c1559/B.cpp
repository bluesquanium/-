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
		char last = s[0];
		for (ll i = 1; i < N; i++) {
			if (s[i] != '?') {
				last = s[i];
				if (s[i - 1] == '?') {
					ll toggle;
					if (s[i] == 'B') {
						toggle = 0;
					}
					else {
						toggle = 1;
					}
					for (ll j = i - 1; j >= 0; j--) {
						if (s[j] != '?') {
							break;
						}
						if (toggle == 0) {
							s[j] = 'R';
						}
						else {
							s[j] = 'B';
						}
						toggle = !toggle;
					}
				}
			}
		}
		if (s[N - 1] == '?') {
			for (ll i = 0; i < N; i++) {
				if (s[i] == '?') {
					if (i == 0) {
						s[i] = 'B';
					}
					else if (s[i - 1] == 'B') {
						s[i] = 'R';
					}
					else {
						s[i] = 'B';
					}
				}
			}
		}

		cout << s << '\n';
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
