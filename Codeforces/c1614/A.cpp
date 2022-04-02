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

ll T, N, L, R, K, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> L >> R >> K;
		m.clear();
		for (ll i = 0; i < N; i++) {
			ll num;
			cin >> num;
			if (num >= L && num <= R) {
				m.push_back(num);
			}
		}

		sort(m.begin(), m.end());

		ans = 0;
		ll sum = 0;
		for (ll i = 0; i < m.size(); i++) {
			if (sum + m[i] <= K) {
				sum += m[i];
				ans++;
			}
			else {
				break;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
