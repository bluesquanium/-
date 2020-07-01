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

ll T, N, M;
vector<ll> m;
vector<ll> ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans.clear();
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		ans.push_back(m[0]);
		for (ll i = 1; i < N - 1; i++) {
			if ((m[i - 1] < m[i] && m[i] > m[i + 1]) || (m[i - 1] > m[i] && m[i] < m[i + 1])) {
				ans.push_back(m[i]);
			}
		}
		ans.push_back(m[N - 1]);

		cout << ans.size() << '\n';
		for (ll i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
