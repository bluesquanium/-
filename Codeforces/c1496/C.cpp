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

ll T, N, M, t1, t2;
double ans;
vector<ll> m1, m2;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		m1.clear(); m1.resize(N);
		m2.clear(); m2.resize(N);
		ll m1Cnt = 0, m2Cnt = 0;
		for (ll i = 0; i < N * 2; i++) {
			cin >> t1 >> t2;
			if (t1 == 0) {
				m2[m2Cnt++] = abs(t2);
			}
			else {
				m1[m1Cnt++] = abs(t1);
			}
		}
		sort(m1.begin(), m1.end());
		sort(m2.begin(), m2.end());
		for (ll i = 0; i < N; i++) {
			ll temp = m1[i] * m1[i] + m2[i] * m2[i];
			ans += sqrt((double)temp);
		}

		cout << fixed;
		cout.precision(15);
		cout << ans << '\n';
	}

	return 0;
}
