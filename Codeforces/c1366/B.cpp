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

ll T, N, X, M, ans;
vector<pll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ll left, right;
		ans = 0;
		cin >> N >> X >> M;
		left = X, right = X;
		m.clear(); m.resize(M);
		for (ll i = 0; i < M; i++) {
			cin >> m[i].first >> m[i].second;
			if (m[i].second < left || right < m[i].first) {

			}
			else {
				left = min(left, m[i].first);
				right = max(right, m[i].second);
			}
		}

		ans = right - left + 1;
		cout << ans << '\n';
	}

	return 0;
}
