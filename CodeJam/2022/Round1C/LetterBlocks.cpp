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

#define ALPHA_A 'A'

ll T, N, M, temp;
string ans, ans_pre;
vector<pll> m;
vector<string> naive;
ll dict[26][4]; // left, center, right, imp
ll ori_dict[26][4];
ll check[100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans.clear();
		ans_pre.clear();

		for (ll i = 0; i < 100; i++) {
			check[i] = 0;
		}
		for (ll i = 0; i < 26; i++) {
			dict[i][0] = dict[i][1] = dict[i][2] = dict[i][3] = 0;
		}
		ll cnt = 0;
		cin >> N;
		m.clear(); m.resize(N);
		naive.clear();
		for (ll i = 0; i < N; i++) {
			string s;
			cin >> s;
			naive.push_back(s);
			m[i].first = s[0];
			m[i].second = s[s.size() - 1];

			ll allSame = 1;
			for (ll j = 1; j < s.size(); j++) {
				if (s[0] != s[j]) {
					allSame = 0;
					break;
				}
			}
			if (allSame) {
				dict[s[0] - ALPHA_A][1]++;
			}
			else {
				if (s[0] == s[s.size() - 1]) {
					ans = "IMPOSSIBLE";
				}
				dict[s[0] - ALPHA_A][0]++;
				dict[s[s.size() - 1] - ALPHA_A][2]++;
				for (ll idx = 1; idx < s.size() - 1; idx++) {
					if (s[idx] != s[0] && s[idx] != s[s.size() - 1]) {
						if (s[idx] != s[idx - 1]) {
							dict[s[idx] - ALPHA_A][3]++;
						}
					}
					else {
						ll isDistinct = 0;
						for (ll j = idx - 1; j > 0; j--) {
							if (s[j] != s[0]) {
								isDistinct = 1;
							}
						}
						if (isDistinct) {
							isDistinct = 0;
							for (ll j = idx + 1; j < s.size() - 1; j++) {
								if (s[j] != s[s.size() - 1]) {
									isDistinct = 1;
								}
							}
							if (isDistinct) {
								dict[s[idx] - ALPHA_A][3]++;
							}
						}
					}
				}
			}
		}

		for (ll i = 0; i < 26; i++) {
			if (dict[i][0] > 1 || dict[i][2] > 1 || dict[i][3] > 1 ||
				(dict[i][3] > 0 && 
				(dict[i][0] > 0 || dict[i][1] > 0 || dict[i][2] > 0))) {
				ans = "IMPOSSIBLE";
				break;
			}
		}

		if (ans.size() == 0) {
			for (ll i = 0; i < 26; i++) {
				ori_dict[i][0] = dict[i][0];
				ori_dict[i][1] = dict[i][1];
				ori_dict[i][2] = dict[i][2];
				ori_dict[i][3] = dict[i][3];
			}
			ll cur[2] = { -1, -1 };
			while (1) {
				ll isUpdate = cnt;
				for (ll i = 0; i < N; i++) {
					if (check[i] == 1) {
						continue;
					}
					if (dict[m[i].first - ALPHA_A][0] == 0 && dict[m[i].first - ALPHA_A][2] == 0 && dict[m[i].first - ALPHA_A][1] > 0
						&& (cur[0] == -1 || cur[0] == m[i].first)) {
						check[i] = 1;
						cur[0] = m[i].first;
						cur[1] = m[i].first;

						dict[m[i].first - ALPHA_A][1]--;
						ans_pre += naive[i];
						cnt++;
					}
				}
				cur[0] = cur[1] = -1;

				if (cnt == isUpdate) {
					break;
				}
			}
			cnt = cnt;
			while (cnt != N) {
				ll isUpdate = cnt;
				for (ll i = 0; i < N; i++) {
					if (check[i] == 1) {
						continue;
					}
					if (cur[1] == -1) {
						check[i] = 1;
						cur[0] = m[i].first;
						cur[1] = m[i].second;
						if (m[i].first == m[i].second) {
							dict[m[i].first - ALPHA_A][1]--;
						}

						ans += naive[i];
						cnt++;
					}
					else {
						if (m[i].first == cur[1]) {
							if (m[i].first != m[i].second && dict[m[i].first - ALPHA_A][1] > 0) {
								continue;
							}
							check[i] = 1;
							cur[1] = m[i].second;
							if (m[i].first == m[i].second) {
								dict[m[i].first - ALPHA_A][1]--;
							}

							ans += naive[i];
							cnt++;
						}
						else if (m[i].second == cur[0]) {
							if (m[i].first != m[i].second && dict[m[i].second - ALPHA_A][1] > 0) {
								continue;
							}
							check[i] = 1;
							cur[0] = m[i].first;
							if (m[i].first == m[i].second) {
								dict[m[i].first - ALPHA_A][1]--;
							}

							ans = naive[i] + ans;
							cnt++;
						}
					}
				}
				if (isUpdate == cnt) {
					if (cur[0] == -1) {
						break;
					}
					else {
						ll isIm = 0;
						ll tdict[26] = { 0 };
						tdict[ans[0] - ALPHA_A] = 1;
						ll prev = ans[0];
						for (ll i = 1; i < ans.size(); i++) {
							if (prev != ans[i]) {
								if (tdict[ans[i] - ALPHA_A] == 1) {
									isIm = 1;
									ans = "IMPOSSIBLE";
									break;
								}
								tdict[ans[i] - ALPHA_A] = 1;
								prev = ans[i];
							}
						}
						if (isIm) {
							break;
						}

						cur[0] = cur[1] = -1;
						ans_pre += ans;
						ans.clear();
					}
				}
			}

			if (cnt != N) {
				ans = "IMPOSSIBLE";
			}
			else if (ans.size() != 0 && cur[0] == cur[1]) {
				for (ll i = 0; i < 26; i++) {
					if (ori_dict[i][0] != 0 || ori_dict[i][1] != 0 || ori_dict[i][2] != 0 || ori_dict[i][3] != 0) {
						if (cur[0] != ALPHA_A + i) {
							ans = "IMPOSSIBLE";
							break;
						}
					}
				}
			}
		}

		ll isIm = 0;
		if (ans.size() == 10) {
			string s = "IMPOSSIBLE";
			isIm = 1;
			for (ll i = 0; i < ans.size(); i++) {
				if (ans[i] != s[i]) {
					isIm = 0;
					break;
				}
			}
		}
		if (isIm == 0) {
			ans = ans_pre + ans;
		}

		cout << "Case #" << t << ": " << ans << '\n';
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
