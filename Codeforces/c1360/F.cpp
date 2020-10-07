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
vector< string > m;
string ans;

ll test(string ans, string target) {
	ll diff = 0;
	for (ll i = 0; i < M; i++) {
		if (target[i] != ans[i]) {
			if (diff) {
				return 0;
			}
			diff++;
		}
	}
	return 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> M;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		ans.clear();
		for (ll j = 0; j < M; j++) {
			for (ll a = 0; a < 26; a++) {
				ans = m[0];
				ans[j] = 'a' + a;

				ll isFailed = 0;
				for (ll k = 1; k < N; k++) {
					if (test(ans, m[k]) == 0) {
						isFailed = 1;
						break;
					}
				}

				if (isFailed == 0) {
					cout << ans << '\n';
					break;
				}
				ans.clear();
			}
			if (ans.size() != 0) {
				break;
			}
		}

		if (ans.size() == 0) {
			cout << "-1\n";
		}
	}

	return 0;
}
