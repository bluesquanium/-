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
vector<ll> m;
ll visited[200000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 1;
		cin >> N;
		m.clear(); m.resize(N);
		memset(visited, 0, sizeof(ll) * N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (visited[(i + (m[i] % N + N) % N) % N] != 0) {
				ans = 0;
			}
			visited[(i + (m[i] % N + N) % N) % N] = 1;
		}

		if (ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
