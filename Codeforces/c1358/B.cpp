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
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}
		sort(m.begin(), m.end());
		for (ll i = 0; i < N; i++) {
			if (m[i] <= i + 1) {
				ans = i + 1;
			}
		}

		cout << ans + 1 << '\n';
	}

	return 0;
}
