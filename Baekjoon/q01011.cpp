#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

#define MAX 99
ll T, X, Y, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	for (ll t = 0; t < T; t++) {
		ans = 0;

		cin >> X >> Y;
		ll num = Y - X;
		ll maxi;
		for (ll i = 1; i < 100000; i++) {
			if (num < i*i) {
				num -= (i-1) * (i-1);
				maxi = i - 1;
				ans += maxi * 2 - 1;
				break;
			}
		}

		if (num) {
			ans += (num + maxi -1) / maxi;
		}

		cout << ans << '\n';
	}

	return 0;
}
