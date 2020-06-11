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

ll N, M, ans;
vector<ll> m;

ll mem[100000][61];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}

	mem[0][m[0] + 30] = m[0];
	for (ll i = 1; i < N; i++) {
		ll maxi = 0;
		for (ll j = -30; j < m[i]; j++) {
			maxi = max(maxi, mem[i - 1][j + 30]);
		}
		for (ll j = m[i]; j <= 30; j++) {
			maxi = max(maxi, mem[i - 1][j + 30]);
			mem[i][j + 30] = maxi + m[i];
			ans = max(ans, mem[i][j + 30] - j);
		}
	}

	cout << ans;

	return 0;
}
