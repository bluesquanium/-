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
ll mem1[26];
ll mem2[26][26];
ll mem3[26][26][26];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		for (ll i = 0; i < 26; i++) {
			mem1[i] = 0;
			for (ll j = 0; j < 26; j++) {
				mem2[i][j] = 0;
				for (ll k = 0; k < 26; k++) {
					mem3[i][j][k] = 0;
				}
			}
		}

		cin >> N;
		string s;
		cin >> s;

		mem1[s[0] - 'a'] = 1;
		mem1[s[1] - 'a'] = 1;
		mem2[s[0] - 'a'][s[1] - 'a'] = 1;
		for (ll i = 2; i < s.size(); i++) {
			mem1[s[i] - 'a'] = 1;
			mem2[s[i - 1] - 'a'][s[i] - 'a'] = 1;
			mem3[s[i - 2] - 'a'][s[i - 1] - 'a'][s[i] - 'a'] = 1;
		}

		ans = 0;
		for (ll i = 0; i < 26; i++) {
			if (mem1[i] == 0) {
				s.clear();
				s.push_back('a' + i);
				ans = 1;
				break;
			}
		}
		if (ans == 0) {
			for (ll i = 0; i < 26; i++) {
				for (ll j = 0; j < 26; j++) {
					if (mem2[i][j] == 0) {
						s.clear();
						s.push_back('a' + i);
						s.push_back('a' + j);
						ans = 1;
						break;
					}
				}

				if (ans) {
					break;
				}
			}
			
			if (ans == 0) {
				for (ll i = 0; i < 26; i++) {
					for (ll j = 0; j < 26; j++) {
						for (ll k = 0; k < 26; k++) {
							if (mem3[i][j][k] == 0) {
								s.clear();
								s.push_back('a' + i);
								s.push_back('a' + j);
								s.push_back('a' + k);
								ans = 1;
								break;
							}
						}

						if (ans) {
							break;
						}
					}

					if (ans) {
						break;
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
