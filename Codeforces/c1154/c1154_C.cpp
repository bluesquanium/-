#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c, week = 2000000000, ans;
int m[7] = { 0,1,2,0,2,1,0 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> a >> b >> c;
	week = min(week, a / 3);
	week = min(week, b / 2);
	week = min(week, c / 2);
	ans = week * 7;
	a -= week * 3;
	b -= week * 2;
	c -= week * 2;
	int maxi = 0;
	for (int d = 0; d < 7; d++) { // Mon ~ Sun
		bool check = true;
		int ta = a, tb = b, tc = c, day = d, step = 0;
		while (check) {
			switch (m[day]) {
			case 0:
				if (ta-- != 0) {
					step++;
				}
				else {
					check = false;
				}
				break;
			case 1:
				if (tb-- != 0) {
					step++;
				}
				else {
					check = false;
				}
				break;
			case 2:
				if (tc-- != 0) {
					step++;
				}
				else {
					check = false;
				}
				break;
			}
			day = (day + 1) % 7;
		}
		maxi = max(maxi, step);
	}

	cout << ans + maxi;

	return 0;
}
