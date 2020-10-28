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
		ll maxi = 0, cnt = 0;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (maxi <= m[i]) {
				if (maxi < m[i]) {
					maxi = m[i];
					cnt = 1;
				}
				else {
					cnt++;
				}
			}
		}

		if (cnt == 1) {
			for (ll i = 0; i < N; i++) {
				if (m[i] == maxi) {
					cout << i + 1 << '\n';
					break;
				}
			}
		}
		else {
			bool pass = false;
			for (ll i = 0; i < N; i++) {
				if (m[i] == maxi) {
					if (i - 1 >= 0 && m[i - 1] < maxi) {
						cout << i + 1 << '\n';
						pass = true;
						break;
					}
					if (i + 1 < N && m[i + 1] < maxi) {
						cout << i + 1 << '\n';
						pass = true;
						break;
					}
				}
			}
			if (pass == false) {
				cout << -1 << '\n';
			}
		}
	}

	return 0;
}
