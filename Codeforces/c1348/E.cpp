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

ll N, K, ans;
pll remains;
vector<pll> m;
bool mem[501][500];
bool ks[500];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	m.resize(N + 1);
	for (ll i = 1; i <= N; i++) {
		cin >> m[i].first >> m[i].second;
		ans += m[i].first + m[i].second;
	}

	mem[0][0] = true;
	for (ll n = 1; n <= N; n++) {
		memset(ks, 0, sizeof(bool) * K);
		ks[m[n].first % K] = true;
		for (ll k = 0; k < K; k++) {
			if (m[n].first >= k && (m[n].first - k) % K + m[n].second >= K) {
				ks[k] = true;
			}
		}

		for (ll k = 0; k < K; k++) {
			if (ks[k]) {
				for (ll i = 0; i < K; i++) {
					if (mem[n - 1][i] == true) {
						mem[n][(k + i) % K] = true;
					}
				}
			}
		}
	}

	for (ll k = 0; k < K; k++) {
		if (mem[N][k]) {
			cout << (ans - k) / K;
			break;
		}
	}

	return 0;
}
