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

ll T, N, K;
string s;

ll cnt[26];
ll targetIdx;
bool check() {
	if (targetIdx == -1) {
		for (ll i = 0; i < 26; i++) {
			if (cnt[i] % K != 0) {
				return false;
			}
		}
		return true;
	}

	ll numJoker = N - targetIdx;
	for (ll i = 0; i < 26; i++) {
		if (cnt[i] % K != 0) {
			numJoker -= K - (cnt[i] % K);
		}

		if (numJoker < 0) {
			return false;
		}
		else if (numJoker == 0) {
			if (s[targetIdx] + 1 - 'a' > i) {
				return false;
			}
		}
	}

	ll needNum = 0;
	for (ll i = 0; i < 26; i++) {
		if (cnt[i] % K != 0) {
			needNum += K - (cnt[i] % K);
		}
	}
	if (needNum != s.size() - targetIdx) {
		s[targetIdx] = s[targetIdx] + 1;
		cnt[s[targetIdx] - 'a']++;
	}
	else {
		ll cur = s[targetIdx] + 1 - 'a';
		while (cur < 26) {
			if (cnt[cur] % K != 0) {
				s[targetIdx] = cur + 'a';
				cnt[cur]++;
				break;
			}
			cur++;
		}
		if (cur == 26) {
			s[targetIdx] = s[targetIdx] + 1;
			cnt[s[targetIdx] - 'a']++;
		}
	}
	
	ll cur = 25;
	for (ll i = s.size() - 1; i > targetIdx; i--) {
		while (cur > 0) {
			if (cnt[cur] % K != 0) {
				s[i] = cur + 'a';
				cnt[cur]++;
				break;
			}
			cur--;
		}
		if (cur == 0) {
			s[i] = 'a';
		}
	}

	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		targetIdx = -1;
		for (ll i = 0; i < 26; i++) {
			cnt[i] = 0;
		}

		cin >> N >> K;
		cin >> s;
		if (N % K != 0) {
			s = "-1";
		}
		else {
			for (ll i = 0; i < s.size(); i++) {
				cnt[s[i] - 'a']++;
			}

			if (!check()) {
				for (targetIdx = s.size() - 1; targetIdx >= 0; targetIdx--) {
					cnt[s[targetIdx] - 'a']--;
					if (s[targetIdx] != 'z') {
						if (check()) {
							break;
						}
					}
				}
			}
		}

		cout << s << '\n';
	}

	return 0;
}
