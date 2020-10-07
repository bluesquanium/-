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
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll N, ans, temp;
string s;
ll mem[10][2];

ll cal(ll num1, ll num2, char cmd) {
	ll ret;
	switch (cmd) {
	case '+':
		ret = num1 + num2;
		break;
	case '-':
		ret = num1 - num2;
		break;
	case '*':
		ret = num1 * num2;
		break;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	cin >> s;

	if (N == 1) {
		cout << s << '\n';
	}
	else {
		mem[0][0] = mem[0][1] = s[0] - '0';
		mem[1][0] = mem[1][1] = cal(s[0] - '0', s[2] - '0', s[1]);
		for (ll i = 2; i * 2 < N; i++) {
			mem[i][0] = max(
				max(
					cal(mem[i - 1][0], s[i * 2] - '0', s[i * 2 - 1]), 
					cal(mem[i - 2][0], cal(s[i * 2 - 2] - '0', s[i * 2] - '0', s[i * 2 - 1]), s[i * 2 - 3])
				),
				max(
					cal(mem[i - 1][1], s[i * 2] - '0', s[i * 2 - 1]),
					cal(mem[i - 2][1], cal(s[i * 2 - 2] - '0', s[i * 2] - '0', s[i * 2 - 1]), s[i * 2 - 3])
				)
			);
			mem[i][1] = min(
				min(
					cal(mem[i - 1][0], s[i * 2] - '0', s[i * 2 - 1]),
					cal(mem[i - 2][0], cal(s[i * 2 - 2] - '0', s[i * 2] - '0', s[i * 2 - 1]), s[i * 2 - 3])
				),
				min(
					cal(mem[i - 1][1], s[i * 2] - '0', s[i * 2 - 1]),
					cal(mem[i - 2][1], cal(s[i * 2 - 2] - '0', s[i * 2] - '0', s[i * 2 - 1]), s[i * 2 - 3])
				)
			);
		}
		cout << mem[(N - 1) / 2][0];
	}

	return 0;
}
