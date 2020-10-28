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
vector<pll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i].first;
			m[i].second = i + 1;
		}
		sort(m.begin(), m.end());
		if (m[0].first == m.back().first) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			ll pidx = m.back().second, curNum = m[0].first;
			for (ll i = 0; i < N - 1; i++) {
				if (m[i].first != curNum) {
					pidx = m[i - 1].second;
					curNum = m[i].first;
				}
				cout << pidx << ' ' << m[i].second << '\n';
			}
		}
	}

	return 0;
}
