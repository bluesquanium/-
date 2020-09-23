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

ll T, N, M, ans, temp;
vector<ll> m;
ll mem[200000][2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		memset(mem, -1, sizeof(ll) * N * 2);
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		if (N == 1) {
			ans = m[0];
		}
		else if (N == 2) {
			mem[0][0] = mem[1][1] = m[0];
			mem[1][0] = m[0] + m[1];
			ans = min(mem[1][0], mem[1][1]);
		}
		else {
			mem[0][0] = mem[1][1] = m[0];
			mem[1][0] = m[0] + m[1];
			mem[2][0] = mem[1][1] + m[2];
			mem[2][1] = min(mem[1][0], mem[0][0]);
			for (ll i = 3; i < N; i++) {
				mem[i][0] = m[i] + min(mem[i-1][1], mem[i-2][1] + m[i-1]);
				mem[i][1] = min(mem[i - 1][0], mem[i - 2][0]);
			}
			ans = min(mem[N - 1][0], mem[N - 1][1]);
		}

		cout << ans << '\n';
	}

	return 0;
}
