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

ll T, N, M, temp;
vector<ll> m;
string ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		string s;
		s = to_string(N + 1);

		ans.clear();
		ll cnt = 0;
		for (ll i = 1; i <= s.size() + 1; i++) {
			if (ans.size() <= s.size()) {
				ans += to_string(i);
			}
		}

		for (ll i = 2; i <= s.size() - 1; i++) {
			string temp;
			ll num = 1;
			for (ll j = 1; j < i; j++) {
				num *= 10;
			}
			while (temp.size() <= s.size()) {
				temp += to_string(num);
				num++;
			}

			if (temp.size() <= ans.size()) {
				ans = temp;
			}
		}

		for (ll i = 1; i <= s.size() - 1; i++) {
			ll isBigger = 0;
			string temp;
			ll curNum = stoll(s.substr(0, i));
			temp = s.substr(0, i);
			for (ll j = i; j < s.size(); j += i) {
				ll num = stoll(s.substr(j, i));
				if (num < curNum + 1) {
					isBigger = 1;
				}

				if (isBigger) {
					temp += to_string(curNum + 1);
					curNum++;
				}
				else if (num == curNum + 1) {
					temp += to_string(curNum + 1);
					curNum++;
				}
				else {
					isBigger = -1;
					break;
				}
			}

			if (isBigger != -1) {
				if (ans.size() > temp.size()) {
					ans = temp;
				}
				else if (ans.size() == temp.size()) {
					for (ll i = 0; i < ans.size(); i++) {
						if (ans[i] > temp[i]) {
							ans = temp;
						}
						else if (ans[i] < temp[i]) {
							break;
						}
					}
				}
			}
		}

		// 처음 수를 1 크게 시작하는거
		for (ll i = 1; i <= s.size() - 1; i++) {
			ll isBigger = 1;
			string temp;
			ll curNum = stoll(s.substr(0, i)) + 1;
			temp = to_string(curNum);
			for (ll j = i; j < s.size() && temp.size() < s.size(); j += i) {
				ll num = stoll(s.substr(j, i));
				if (num < curNum + 1) {
					isBigger = 1;
				}

				if (isBigger) {
					temp += to_string(curNum + 1);
					curNum++;
				}
				else if (num == curNum + 1) {
					temp += to_string(curNum + 1);
					curNum++;
				}
				else {
					isBigger = -1;
					break;
				}
			}

			if (isBigger != -1) {
				if (ans.size() > temp.size()) {
					ans = temp;
				}
				else if (ans.size() == temp.size()) {
					for (ll i = 0; i < ans.size(); i++) {
						if (ans[i] > temp[i]) {
							ans = temp;
						}
						else if (ans[i] < temp[i]) {
							break;
						}
					}
				}
			}
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
