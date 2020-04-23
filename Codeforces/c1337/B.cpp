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

ll T, X, N, M;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> X >> N >> M;
		if (X > 20) {
			while(N--) {
				X = X / 2 + 10;
			}
		}
		while(M--) {
			X -= 10;
		}

		if (X <= 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
