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
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

ll T, N, P, ans, temp;
vector<ll> m;
vector<pll> smallValues;
set<ll> visited[200001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N >> P;
		smallValues.clear();
		for (ll i = 0; i < N; i++) {
			visited[i].clear();
		}
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (m[i] < P) {
				smallValues.push_back({m[i], i});
			}
		}
		sort(smallValues.begin(), smallValues.end());

		for (ll i = 0; i < smallValues.size(); i++) {
			ll mini = smallValues[i].first;
			ll idx = smallValues[i].second;
			if (visited[idx].count(mini) == 0) {
				visited[idx].insert(mini);
				for (ll j = idx + 1; j < N; j++) {
					if (m[j] % mini == 0) {
						visited[j].insert(mini);
					}
					else {
						break;
					}
				}
				for (ll j = idx - 1; j >= 0; j--) {
					if (m[j] % mini == 0) {
						visited[j].insert(mini);
					}
					else {
						break;
					}
				}
			}
		}

		for (ll i = 0; i < N - 1; i++) {
			int check = 0;
			for (auto iter1 = visited[i].begin(); iter1 != visited[i].end(); iter1++) {
				if (visited[i + 1].count(*iter1) != 0) {
					ans += *iter1;
					check = 1;
					break;
				}
			}
			if (check == 0) {
				ans += P;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}

/*
0. Enough array size? Enough array size? Integer overflow?

1. Think TWICE, Code ONCE!
Are there any counterexamples to your algo?

2. Be careful about the BOUNDARIES!
N=1? P=1? Something about 0?

3. Do not make STUPID MISTAKES!
Time complexity? Memory usage? Precision error?

4. Be careful to wrong variable.
*/
