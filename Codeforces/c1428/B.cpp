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

ll T, N, M, ans, temp;
ll check[300001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		memset(check, 0, sizeof(ll) * N);
		string s;
		cin >> s;
		ll cmd[2] = { 0 };
		for (ll i = 0; i < N; i++) {
			if (s[i] == '<') {
				cmd[0] = 1;
			}
			else if(s[i] == '>') {
				cmd[1] = 1;
			}
			if (s[i] == '-') {
				check[i] = 1;
				check[(i + 1) % N] = 1;
			}
		}

		if (cmd[0] == 0 || cmd[1] == 0) {
			cout << N << '\n';
		}
		else {
			ans = 0;
			for (ll i = 0; i < N; i++) {
				if (check[i]) {
					ans++;
				}
			}
			cout << ans << '\n';
		}
	}

	return 0;
}
