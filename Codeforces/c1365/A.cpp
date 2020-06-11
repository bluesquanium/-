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
ll m[50][50];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> M;
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < M; j++) {
				cin >> m[i][j];
			}
		}

		ll hor = 0, ver = 0;
		for (ll i = 0; i < N; i++) {
			bool check = true;
			for (ll j = 0; j < M; j++) {
				if (m[i][j] == 1) {
					check = false;
					break;
				}
			}
			if (check) {
				hor++;
			}
		}
		for (ll i = 0; i < M; i++) {
			bool check = true;
			for (ll j = 0; j < N; j++) {
				if (m[j][i] == 1) {
					check = false;
					break;
				}
			}
			if (check) {
				ver++;
			}
		}

		ans = min(hor, ver);

		if (ans % 2 == 0) {
			cout << "Vivek\n";
		}
		else {
			cout << "Ashish\n";
		}
	}

	return 0;
}
