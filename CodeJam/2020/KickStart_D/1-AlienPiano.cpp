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

ll T, K, ans;
vector<ll> m;
ll mem[2][4];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		memset(mem[0], 0, sizeof(ll) * 4);
		memset(mem[1], 0, sizeof(ll) * 4);
		cin >> K;
		m.clear(); m.resize(K);
		for (ll i = 0; i < K; i++) {
			cin >> m[i];
		}

		// cur == i%2
		// prev == (i + 1)%2
		for (ll i = 1; i < K; i++) {
			ll cur = i % 2, prev = (i + 1) % 2;
			if (m[i - 1] < m[i]) {
				ll temp = mem[prev][3] + 1;
				
				mem[cur][3] = min(mem[prev][2], min(mem[prev][1], mem[prev][0]));
				mem[cur][2] = min(mem[prev][1], mem[prev][0]);
				mem[cur][1] = mem[prev][0];
				mem[cur][0] = temp;
				for (ll j = 0; j < 4; j++) {
					mem[cur][j] = min(mem[cur][j], temp);
				}
			}
			else if (m[i - 1] > m[i]) {
				ll temp = mem[prev][0] + 1;

				mem[cur][0] = min(mem[prev][1], min(mem[prev][2], mem[prev][3]));
				mem[cur][1] = min(mem[prev][2], mem[prev][3]);
				mem[cur][2] = mem[prev][3];
				mem[cur][3] = temp;
				for (ll j = 0; j < 4; j++) {
					mem[cur][j] = min(mem[cur][j], temp);
				}
			}
		}

		ans = INF;
		for (ll i = 0; i < 4; i++) {
			ans = min(ans, mem[(K - 1) % 2][i]);
		}
		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}
