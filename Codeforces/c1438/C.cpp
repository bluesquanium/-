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
ll m[100][100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> M;
		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < M; j++) {
				cin >> m[i][j];
				if (m[i][j] % 2 == 0 && (i + j) % 2 == 1) {
					m[i][j]++;
				}
				else if (m[i][j] % 2 == 1 && (i + j) % 2 == 0) {
					m[i][j]++;
				}
			}
		}

		for (ll i = 0; i < N; i++) {
			for (ll j = 0; j < M; j++) {
				cout << m[i][j] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}
