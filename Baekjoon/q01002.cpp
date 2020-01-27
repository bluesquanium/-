#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll T, X[2], Y[2], R[2], ans;

ll mabs(ll a) {
	return a > 0 ? a : -a;
}

ll mpow(ll a) {
	return a * a;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> T;
	for (ll t = 0; t < T; t++) {
		cin >> X[0] >> Y[0] >> R[0] >> X[1] >> Y[1] >> R[1];

		if (X[0] == X[1] && Y[0] == Y[1] && R[0] == R[1]) {
			ans = -1;
		}
		else {
			ll betweenTurretDistancePow = mpow(mabs(X[0] - X[1])) + mpow(mabs(Y[0] - Y[1]));
			ll difRPow = (R[0] - R[1]) * (R[0] - R[1]);
			ll sumRPow = mpow(R[0] + R[1]);
			ll num = sumRPow - betweenTurretDistancePow;
			if (num == 0) {
				ans = 1;
			}
			else if (num > 0) {
				num = difRPow - betweenTurretDistancePow;
				if (num == 0) {
					ans = 1;
				}
				else if (num < 0) {
					ans = 2;
				}
				else {
					ans = 0;
				}
			}
			else {
				ans = 0;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
