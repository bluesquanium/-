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

		for (ll i = 1; i < N; i++) {
			if (m[i] < m[i - 1]) {
				ll height = m[i - 1];
				ll mini = m[i];
				ll isEnd = 0;
				for (ll j = i + 1; j < N; j++) {
					if (j == N - 1) {
						isEnd = 1;
					}
					if (m[i - 1] <= m[j]) {
						m[j - 1] = height;
						i = j - 1;
						break;
					}
					
					if (mini > m[j]) {
						mini = m[j];
					}
				}
				ans += height - mini;
				if (isEnd) {
					break;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
