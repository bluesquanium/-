#include <iostream>
#include <cmath>
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

ll T, N, M, ans;
ll m[300][300];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 1;
		cin >> N >> M;
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < M; j++) {
				cin >> m[i][j];
			}
		}

		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < M; j++) {
				ll isSuf[2] = { 0, };
				if (i == 0 || i == N - 1) {
					isSuf[0] = 1;
				}
				if (j == 0 || j == M - 1) {
					isSuf[1] = 1;
				}

				switch (isSuf[0] + isSuf[1]) {
				case 0:
					if (m[i][j] > 4) {
						ans = 0;
					}
					else {
						m[i][j] = 4;
					}
					break;
				case 1:
					if (m[i][j] > 3) {
						ans = 0;
					}
					else {
						m[i][j] = 3;
					}
					break;
				case 2:
					if (m[i][j] > 2) {
						ans = 0;
					}
					else {
						m[i][j] = 2;
					}
					break;
				}

				if (ans == 0) {
					break;
				}
			}
			if (ans == 0) {
				break;
			}
		}
		
		if (ans == 0) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			for (ll i = 0; i < N; i++) {
				for (ll j = 0; j < M; j++) {
					cout << m[i][j] << ' ';
				}
				cout << '\n';
			}
		}

	}

	return 0;
}
