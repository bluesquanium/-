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
vector<ll> m, target;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		m.clear(); target.clear();
		cin >> N >> M;
		m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}
		target = m;
		sort(target.begin(), target.end());
		ll i = 0;
		while (!target.empty()) {
			if (target.back() == m[i]) {
				ans++;
				if (i == M) {
					break;
				}

				m[i] = -1;
				target.pop_back();
			}

			i = (i + 1) % N;
		}

		cout << ans << '\n';
	}

	return 0;
}
