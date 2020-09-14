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

ll T, N, ans;
string s;
#define MEM_MAX 2000000
#define MEM_CONST 1000000
ll mem[MEM_MAX][2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		ll base = 0;
		cin >> N;
		cin >> s;
		for (ll i = 0; i < N; i++) {
			ll num = s[i] - '0';
			if (num == 1) {
				ans++;
			}
			ll target = -(num - 1) - base + MEM_CONST;
			if (mem[target][1] == t) {
				ans += mem[target][0];
			}

			base += num - 1;
			target = num - 1 - base + MEM_CONST;
			if (mem[target][1] != t) {
				mem[target][1] = t;
				mem[target][0] = 1;
			}
			else {
				mem[target][0]++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
