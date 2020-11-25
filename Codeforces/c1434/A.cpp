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

ll N, M, ans, temp;
vector<pll> m;
ll a[6];
ll visited[100000], vCnt;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (ll i = 0; i < 6; i++) {
		cin >> a[i];
	}
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> temp;
		for (ll j = 0; j < 6; j++) {
			m.push_back({ temp - a[j], i });
		}
	}
	sort(m.begin(), m.end());

	ans = INF;
	ll rightCur = 0;
	for (ll i = 0; i < m.size(); i++) {
		if (i != 0) {
			if (--visited[m[i - 1].second] == 0) {
				vCnt--;
			}
		}
		while (rightCur < m.size()) {
			if (vCnt == N) {
				break;
			}

			if (visited[m[rightCur].second] == 0) {
				vCnt++;
			}
			visited[m[rightCur].second]++;
			rightCur++;
		}
		if (vCnt == N) {
			ans = min(ans, m[rightCur - 1].first - m[i].first);
		}
	}

	cout << ans;

	return 0;
}
