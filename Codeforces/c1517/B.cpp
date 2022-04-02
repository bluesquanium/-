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

ll T, N, M, temp;
vector<ll> m[101];
ll mCnt[101];
vector<ll> ans[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> M;
		for (ll i = 0; i < M; i++) {
			ans[i].clear();
			ans[i].resize(N);
		}
		for (ll i = 0; i < N; i++) {
			mCnt[i] = 0;
			m[i].clear();
			m[i].resize(M);
			for (ll j = 0; j < M; j++) {
				cin >> m[i][j];
			}
			sort(m[i].begin(), m[i].end());
		}

		for (ll j = 0; j < M; j++) {
			ll mini = INF, idx = -1;
			for (ll i = 0; i < N; i++) {
				if (mini > m[i][mCnt[i]]) {
					mini = m[i][mCnt[i]];
					idx = i;
				}
			}

			for (ll i = 0; i < N; i++) {
				if (idx != i) {
					ans[j][i] = m[i].back();
					m[i].pop_back();
				}
				else {
					ans[j][i] = m[idx][mCnt[idx]];
					mCnt[idx]++;
				}
			}
		}

		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < M; j++) {
				cout << ans[j][i] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}

	return 0;
}

/*
0. Enough array size? Enough array size? Integer overflow?

1. Think TWICE, Code ONCE!
Are there any counterexamples to your algo?

2. Be careful about the BOUNDARIES!
N=1? P=1? Something about 0?

3. Do not make STUPID MISTAKES!
Time complexity? Memory usage? Precision error?

4. Be careful to wrong variable.
*/
