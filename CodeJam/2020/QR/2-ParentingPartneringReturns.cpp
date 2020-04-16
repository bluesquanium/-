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
#define plll pair< pll, ll>
using namespace std;

ll T, N, S, E;
vector<plll> m;
vector<pll> tt[2];
string ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		tt[0].clear(); tt[1].clear();
		tt[0].emplace_back(-1, 0); tt[1].emplace_back(-1, 0);
		ans.clear();
		cin >> N;
		m.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> m[i].first.first >> m[i].first.second;
			m[i].second = i;
		}
		sort(m.begin(), m.end());

		ans.resize(N);
		for (int i = 0; i < N; i++) {
			if (tt[0].back().second <= m[i].first.first) {
				tt[0].emplace_back(m[i].first);
				ans[m[i].second] = 'J';
			}
			else if(tt[1].back().second <= m[i].first.first) {
				tt[1].emplace_back(m[i].first);
				ans[m[i].second] = 'C';
			}
			else {
				ans = "IMPOSSIBLE";
				break;
			}
		}

		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}
