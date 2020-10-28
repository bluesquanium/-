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

#define TMAX 400

ll T, N, M, ans, temp;
vector<ll> m;
ll mem[200][TMAX + 1];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}
		sort(m.begin(), m.end());
		
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j <= TMAX; j++) {
				mem[i][j] = -1;
			}
		}

		for (ll j = 1; j <= TMAX; j++) {
			mem[0][j] = abs(m[0] - j);
		}

		for (ll i = 1; i < N; i++) {
			ll mini = LINF;
			for (ll j = 1; j <= TMAX; j++) {
				if (mem[i - 1][j - 1] != -1) {
					mini = min(mini, mem[i - 1][j - 1]);
				}

				if (mini != LINF) {
					mem[i][j] = mini + abs(m[i] - j);
				}
			}
		}

		ll mini = LINF;
		for (ll j = 1; j <= TMAX; j++) {
			if (mem[N - 1][j] != -1) {
				mini = min(mini, mem[N - 1][j]);
			}
		}
		cout << mini << '\n';
	}

	return 0;
}
