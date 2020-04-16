#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int X, Y, step = 1, dir = 1, ans;

int abs(int num) {
	return num > 0 ? num : -num;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> X >> Y;

	while (1) {
		if (dir == 1) {
			if (X < Y && Y <= X + step) {
				ans += Y - X;
				break;
			}
		}
		else {
			if (X - step <= Y && Y < X) {
				ans += X - Y;
				break;
			}
		}
		ans += step * 2;
		dir *= -1;
		step *= 2;
	}

	cout << ans;

	return 0;
}
