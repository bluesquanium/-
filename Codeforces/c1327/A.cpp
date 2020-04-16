#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<ll,ll>
using namespace std;

ll T, N, K, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll i = 0; i < T; i++) {
		cin >> N >> K;
		ans = N - K;
		if (ans % 2 == 1 || ans < 0) {
			cout << "NO\n";
		}
		else {
			ans /= 2;
			if (ans >= (K - 1) * K / 2) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}
