#include <iostream>
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

ll T, A, B, C, D, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> A >> B >> C >> D;

		if (B >= A) {
			ans = B;
		}
		else if (D >= C) {
			ans = -1;
		}
		else {
			A -= B;
			ans = B + (A + C - D - 1) / (C - D) * C;
		}

		cout << ans << '\n';
	}

	return 0;
}
