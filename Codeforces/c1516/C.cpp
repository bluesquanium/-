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

ll N, M, ans, temp;
vector<pll> m;

ll mem[101][100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	ll sum = 0;
	for (ll i = 0; i < N; i++) {
		cin >> m[i].first;
		m[i].second = m[i].first;
		sum += m[i].first;
	}

	if (sum % 2 != 1) {
		ans = 0;
		ll K = sum / 2;
		for (int i = m[0].first; i <= K; i++) {
			mem[0][i] = m[0].second;
		}
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < m[i].first; j++) {
				mem[i][j] = mem[i - 1][j];
			}
			for (int j = m[i].first; j <= K; j++) {
				mem[i][j] = max(m[i].second + mem[i - 1][j - m[i].first], mem[i - 1][j]);
			}
		}

		if (mem[N - 1][K] != K) {
			ans = 0;
		}
		else {
			ll mini = INF, idx = -1;
			for (ll i = 0; i < N; i++) {
				if (m[i].first % 2 == 1) {
					idx = i;
					break;
				}
				if (mini > m[i].first) {
					mini = m[i].first;
					idx = i;
				}
			}
			ans = idx + 1;
		}
	}

	if (ans == 0) {
		cout << 0 << '\n';
	}
	else {
		cout << 1 << '\n';
		cout << ans << '\n';
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
