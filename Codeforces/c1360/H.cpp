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
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll T, N, M, temp;
string s;
vector<ll> m, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans.clear();
		m.clear();
		cin >> N >> M;
		for (ll i = 0; i < N; i++) {
			cin >> s;
			ll num = 0;
			for (ll i = 0; i < M; i++) {
				num *= 2;
				num += s[i] - '0';
			}
			m.push_back(num);
		}
		sort(m.begin(), m.end());

		ll target = pow(2, M);
		target = target - N - 1;
		target /= 2;

		for (ll i = 0; i < m.size(); i++) {
			if (m[i] <= target) {
				target++;
			}
			else {
				break;
			}
		}

		while (target) {
			ans.push_back(target % 2);
			target /= 2;
		}
		while (ans.size() < M) {
			ans.push_back(0);
		}

		for (ll i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i];
		}
		cout << '\n';
	}

	return 0;
}
