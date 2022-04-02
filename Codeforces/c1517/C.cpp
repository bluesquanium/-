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

#define DIR 2
ll dy[DIR] = { 0, 1 };
ll dx[DIR] = { -1, 0 };

ll N, M, ans, temp;
vector<ll> m;
ll mem[500][500];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		mem[i][i] = m[i];
	}

	for (ll i = 0; i < N; i++) {
		ll x = i, y = i;
		ll cnt = 1;
		while (cnt < m[i]) {
			for (ll d = 0; d < DIR; d++) {
				ll ny = y + dy[d], nx = x + dx[d];
				if (0 <= ny && ny < N &&
					0 <= nx && nx < N) {
					if (mem[ny][nx] == 0) {
						mem[ny][nx] = m[i];
						y = ny;
						x = nx;
						cnt++;
						break;
					}
				}
			}

		}
	}
	
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j <= i; j++) {
			cout << mem[i][j] << ' ';
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
