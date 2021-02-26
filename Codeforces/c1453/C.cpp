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

ll T, N, M, temp;
ll ans[10];
char m[2001][2001];

int main(void) {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
		}

		for (ll d = 0; d < 10; d++) {
			ans[d] = 0;
		}
		for (ll digit = 0; digit < 10; digit++) {
			pll dot = { -1, -1 };
			for (ll i = 0; i < N; i++) {
				for (ll j = 0; j < N; j++) {
					if (m[i][j] - '0' == digit) {
						if (dot.first == -1) {
							dot = { i , j };
						}
						else {
							ans[digit] = max(ans[digit], abs(i - dot.first) * max(N - 1 - j, j));
						}
					}
				}
			}
			dot = { -1, -1 };
			for (ll i = N - 1; i >= 0; i--) {
				for (ll j = 0; j < N; j++) {
					if (m[i][j] - '0' == digit) {
						if (dot.first == -1) {
							dot = { i , j };
						}
						else {
							ans[digit] = max(ans[digit], abs(i - dot.first) * max(N - 1 - j, j));
						}
					}
				}
			}
			dot = { -1, -1 };
			for (ll j = 0; j < N; j++) {
				for (ll i = 0; i < N; i++) {
					if (m[i][j] - '0' == digit) {
						if (dot.first == -1) {
							dot = { i , j };
						}
						else {
							ans[digit] = max(ans[digit], abs(j - dot.second) * max(N - 1 - i, i));
						}
					}
				}
			}
			dot = { -1, -1 };
			for (ll j = N - 1; j >= 0; j--) {
				for (ll i = 0; i < N; i++) {
					if (m[i][j] - '0' == digit) {
						if (dot.first == -1) {
							dot = { i , j };
						}
						else {
							ans[digit] = max(ans[digit], abs(j - dot.second) * max(N - 1 - i, i));
						}
					}
				}
			}
		}

		for (ll i = 0; i < 10; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
