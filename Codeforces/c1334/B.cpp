#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll T, N, X, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ans = 0;
		cin >> N >> X;
		m.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> m[i];
		}
		sort(m.rbegin(), m.rend());
		ll sum = 0;
		for (int i = 0; i < N; i++) {
			sum += m[i];
			if (sum / (i + 1) >= X) {
				ans++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
