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

ll color[11] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

ll T, N, M;
vector<ll> m, ans;
ll visited[11], vCnt;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans.clear();
		memset(visited, 0, sizeof(ll) * 11);
		vCnt = 0;
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			for (ll j = 0; j < 11; j++) {
				if (m[i] % color[j] == 0) {
					if (visited[j] == 0) {
						visited[j] = ++vCnt;
					}
					ans.push_back(visited[j]);
					break;
				}
			}
		}
		cout << vCnt << '\n';
		for (ll i = 0; i < N; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
