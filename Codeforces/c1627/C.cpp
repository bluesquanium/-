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
vector<ll> u, v, m;
ll cnt[100001];
ll con[100001][2];
ll conNum[100001][2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		u.clear(); u.resize(N - 1);
		v.clear(); v.resize(N - 1);
		m.clear(); m.resize(N - 1);
		for (ll i = 0; i <= N; i++) {
			cnt[i] = 0;
			con[i][0] = 0;
			con[i][1] = 0;
		}
		ans = 0;
		for (ll i = 0; i < N - 1; i++) {
			cin >> u[i] >> v[i];
			cnt[u[i]]++;
			cnt[v[i]]++;
			if (cnt[u[i]] > 2 || cnt[v[i]] > 2) {
				ans = -1;
			}
			else {
				if (con[u[i]][0] == 0) {
					con[u[i]][0] = v[i];
					conNum[u[i]][0] = i;
				}
				else {
					con[u[i]][1] = v[i];
					conNum[u[i]][1] = i;
				}
				if (con[v[i]][0] == 0) {
					con[v[i]][0] = u[i];
					conNum[v[i]][0] = i;
				}
				else {
					con[v[i]][1] = u[i];
					conNum[v[i]][1] = i;
				}
			}
		}

		if (ans != -1) {
			ll cur;
			for (ll i = 1; i <= N; i++) {
				if (cnt[i] == 1) {
					cur = i;
					break;
				}
			}

			ll toggle = 0;
			ll candi[2] = { 2, 3 };
			
			m[conNum[cur][0]] = candi[toggle];
			toggle = !toggle;
			ll prev = cur;
			cur = con[cur][0];

			for (ll i = 0; i < N - 2; i++) {
				if (con[cur][0] == prev) {
					m[conNum[cur][1]] = candi[toggle];
					toggle = !toggle;

					prev = cur;
					cur = con[cur][1];
				}
				else {
					m[conNum[cur][0]] = candi[toggle];
					toggle = !toggle;

					prev = cur;
					cur = con[cur][0];
				}
			}

			for (ll i = 0; i < N - 1; i++) {
				cout << m[i] << ' ';
			}
		}
		else {
			cout << -1;
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
