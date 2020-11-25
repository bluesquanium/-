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

ll T, N, Q, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		string s;
		cin >> N >> Q;
		cin >> s;
		for (ll q = 0; q < Q; q++) {
			ans = 0;
			ll l, r;
			cin >> l >> r;
			l--; r--;
			for (ll i = l - 1; i >= 0; i--) {
				if (s[i] == s[l]) {
					ans = 1;
					break;
				}
			}
			for (ll i = r + 1; i < N; i++) {
				if (s[i] == s[r]) {
					ans = 1;
					break;
				}
			}

			if (ans) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}
