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

ll N, M, ans;
ll m[50][9];
ll seq[9];
ll visited[9];

void solve(ll cnt) {
	if (cnt == 9) {
		ll score = 0;
		//simulate
		ll cur = 0;
		for (ll n = 0; n < N; n++) {
			ll out = 0;
			ll base[3] = { 0, 0, 0 };
			while (out < 3) {
				switch (m[n][seq[cur]]) {
				case 0:
					out++;
					break;
				case 1:
					score += base[2];
					base[2] = base[1];
					base[1] = base[0];
					base[0] = 1;
					break;
				case 2:
					score += base[1] + base[2];
					base[2] = base[0];
					base[1] = 1;
					base[0] = 0;
					break;
				case 3:
					score += base[0] + base[1] + base[2];
					base[2] = 1;
					base[1] = 0;
					base[0] = 0;
					break;
				case 4:
					score += 1 + base[0] + base[1] + base[2];
					base[2] = 0;
					base[1] = 0;
					base[0] = 0;
					break;
				}

				cur = (cur + 1) % 9;
			}
		}

		ans = max(ans, score);

		return;
	}

	if (cnt == 3) {
		seq[cnt] = 0;
		solve(cnt + 1);
	}
	else {
		for (ll i = 1; i < 9; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				seq[cnt] = i;
				solve(cnt + 1);
				visited[i] = 0;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < 9; j++) {
			cin >> m[i][j];
		}
	}

	visited[0] = 1;
	solve(0);

	cout << ans;

	return 0;
}
