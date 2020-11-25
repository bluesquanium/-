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

ll T, N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		ans = 1;
		bool isDesc = true;
		ll mini = m[0], maxi = 0;
		for (ll i = 1; i < N; i++) {
			if (isDesc) {
				if (maxi == 0) {
					mini = min(mini, m[i]);
				}
				if (m[i - 1] < m[i]) {
					if (maxi != 0) {
						mini = mini - maxi + m[i - 1];
						if (mini < 0) {
							ans = 0;
							break;
						}
					}

					isDesc = false;
				}
			}
			else {
				if (m[i - 1] > m[i]) {
					isDesc = true;
					maxi = m[i - 1];
				}
			}
		}

		if (isDesc && mini < maxi - m[N - 1]) {
			ans = 0;
		}

		if (ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
