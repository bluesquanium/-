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

ll T, N, M, ans;
vector<pll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ans = LINF;
		cin >> N;
		m.clear();
		m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i].first >> m[i].second;
		}
		ll sum = 0;
		for (ll i = 0; i < N; i++) {
			if (m[i].first - m[(i - 1 + N) % N].second > 0) {
				sum += m[i].first - m[(i - 1 + N) % N].second;
			}
		}
		for (ll i = 0; i < N; i++) {
			ll c = 0;
			if (m[i].first - m[(i - 1 + N) % N].second > 0) {
				c = m[i].first - m[(i - 1 + N) % N].second;
			}
			ans = min(ans, sum - c + m[i].first);
		}

		cout << ans << '\n';
	}

	return 0;
}
