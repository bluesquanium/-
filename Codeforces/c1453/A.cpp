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

ll T, N, M, ans, temp;
vector<ll> n, m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> M;
		m.clear(); m.resize(M);
		n.clear(); n.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> n[i];
		}
		for (ll i = 0; i < M; i++) {
			cin >> m[i];
		}

		ans = 0;
		ll nCnt = 0, mCnt = 0;
		while (nCnt < N && mCnt < M) {
			if (n[nCnt] == m[mCnt]) {
				ans++;
				nCnt++;
				mCnt++;
			}
			else if (n[nCnt] < m[mCnt]) {
				nCnt++;
			}
			else {
				mCnt++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
