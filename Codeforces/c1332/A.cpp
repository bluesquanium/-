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

ll T, A, B, C, D, X, Y, X1, Y1, X2, Y2, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 1;
		cin >> A >> B >> C >> D;
		cin >> X >> Y >> X1 >> Y1 >> X2 >> Y2;

		ll hor = B - A, ver = D - C;

		if (hor == 0 && A != 0) {
			if (abs(X - X1) == 0 && abs(X - X2) == 0) {
				ans = 0;
			}
		}
		else {
			if (hor < 0) {
				if (X - X1 < abs(hor)) {
					ans = 0;
				}
			}
			else {
				if (X2 - X < abs(hor)) {
					ans = 0;
				}
			}
		}
		
		if (ver == 0 && C != 0) {
			if (abs(Y - Y1) == 0 && abs(Y - Y2) == 0) {
				ans = 0;
			}
		}
		else {
			if (ver < 0) {
				if (Y - Y1 < abs(ver)) {
					ans = 0;
				}
			}
			else {
				if (Y2 - Y < abs(ver)) {
					ans = 0;
				}
			}
		}

		if (ans) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}
