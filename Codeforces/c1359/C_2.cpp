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

ll T, H, C, Target, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> H >> C >> Target;

		if (2 * Target == C + H) {
			ans = 2;
		}
		else if (2 * Target < H + C) {
			ans = 2;
		}
		else {
			ans = (H - Target) / (2 * Target - C - H);

			if (abs((ans * (H + C) + H - (2 * ans + 1) * Target) * (2 * ans + 3)) >
				abs(((ans + 1) * (H + C) + H - (2 * ans + 3) * Target) * (2 * ans + 1))) {
				ans++;
			}

			ans = ans * 2 + 1;
		}

		cout << ans << '\n';
	}

	return 0;
}
