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
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;
		if (N % 2 == 0) { // even
			for (ll i = N - 1; i > 0; i--) {
				ll toggle = -1;
				for (ll j = 0; j < i; j++) {
					if (i % 2 == 1 && j == 0) {
						cout << 0 << ' ';
					}
					else {
						cout << toggle << ' ';
					}
					toggle *= -1;
				}
			}
			cout << '\n';
		}
		else { // odd
			for (ll i = N - 1; i > 0; i--) {
				ll toggle = 1;
				for (ll j = 0; j < i; j++) {
					cout << toggle << ' ';
					toggle *= -1;
				}
			}
			cout << '\n';
		}
	}

	return 0;
}
