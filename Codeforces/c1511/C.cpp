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

ll N, Q, M, ans, temp;
vector<ll> m, t;
ll pos[51];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> Q;
	m.resize(N);
	t.resize(Q);
	for (ll i = 0; i < 51; i++) {
		pos[i] = -1;
	}
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		if (pos[m[i]] == -1) {
			pos[m[i]] = i;
		}
	}
	for (ll i = 0; i < Q; i++) {
		cin >> t[i];
		cout << pos[t[i]] + 1 << ' ';

		for (ll j = 1; j <= 50; j++) {
			if (j != t[i] && pos[j] < pos[t[i]]) {
				pos[j]++;
			}
		}

		pos[t[i]] = 0;
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
