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
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

ll T, N, K, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> K;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		ans = INF;
		for (ll c = 1; c <= 100; c++) {
			ll painting = false, pCnt = 0;
			ll cnt = 0;
			for (ll i = 0; i < N; i++) {
				if (painting == false) {
					if (m[i] != c) {
						if (K != 1) {
							painting = true;
							pCnt = 1;
						}
						cnt++;
					}
				}
				else {
					pCnt++;
					if (pCnt == K) {
						painting = false;
					}
				}
			}
			ans = min(ans, cnt);
		}

		cout << ans << '\n';
	}

	return 0;
}
