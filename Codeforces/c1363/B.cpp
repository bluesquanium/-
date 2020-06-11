#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll T, N, M, ans;
string s;
ll mem[1000][2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> s;

		if (s[0] == '0') {
			mem[0][0] = 0;
			mem[0][1] = 1;
		}
		else {
			mem[0][0] = 1;
			mem[0][1] = 0;
		}
		for (ll i = 1; i < s.size(); i++) {
			mem[i][0] = mem[i - 1][0];
			mem[i][1] = min(mem[i - 1][0], mem[i - 1][1]);
			if (s[i] == '0') {
				mem[i][1] += 1;
			}
			else {
				mem[i][0] += 1;
			}
		}
		ans = min(mem[s.size() - 1][0], mem[s.size() - 1][1]);

		if (s[0] == '1') {
			mem[0][0] = 0;
			mem[0][1] = 1;
		}
		else {
			mem[0][0] = 1;
			mem[0][1] = 0;
		}
		for (ll i = 1; i < s.size(); i++) {
			mem[i][0] = mem[i - 1][0];
			mem[i][1] = min(mem[i - 1][0], mem[i - 1][1]);
			if (s[i] == '1') {
				mem[i][1] += 1;
			}
			else {
				mem[i][0] += 1;
			}
		}
		ans = min(ans, min(mem[s.size() - 1][0], mem[s.size() - 1][1]));

		cout << ans << '\n';
	}

	return 0;
}
