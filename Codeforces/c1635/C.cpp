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
vector<ll> m;

class Cmd {
public:
	ll x, y, z;
};
vector<Cmd> a;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		m.clear(); m.resize(N);
		a.clear();

		ans = 0;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}
		
		// leftmostPos
		ll lmp = -1;
		ll lmpCur = -1;
		for (ll i = N - 1; i >= 0; i--) {
			if (m[i] >= 0) {
				lmp = m[i];
				lmpCur = i;
				break;
			}
		}

		for (ll i = N - 2; i >= 0; i--) {
			if (m[i] > m[i + 1]) {
				if (lmp == -1 || i + 2 > lmpCur) {
					ans = -1;
					break;
				}

				ans++;

				Cmd tmp;
				tmp.x = i + 1; tmp.y = i + 2; tmp.z = lmpCur + 1;
				m[i] = m[i + 1] - m[lmpCur];
				a.push_back(tmp);
			}
		}

		cout << ans << '\n';
		if (ans != -1) {
			for (ll i = 0; i < ans; i++) {
				cout << a[i].x << ' ' << a[i].y << ' ' << a[i].z << '\n';
			}
		}
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
