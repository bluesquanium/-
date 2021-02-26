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

double e = 1e-6;
double d = 1e-6;

ll ax, ay, bx, by, cx, cy, dx, dy;
double ans;

double calSlope(double val) {
	double y1, x1, y2, x2;
	y1 = ay + (by - ay) * val;
	x1 = ax + (bx - ax) * val;
	y2 = cy + (dy - cy) * val;
	x2 = cx + (dx - cx) * val;

	double ret = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

	y1 = ay + (by - ay) * (val + d);
	x1 = ax + (bx - ax) * (val + d);
	y2 = cy + (dy - cy) * (val + d);
	x2 = cx + (dx - cx) * (val + d);

	double dret = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

	return dret - ret;
}

double calDistance(double val) {
	double y1, x1, y2, x2;
	y1 = ay + (by - ay) * val;
	x1 = ax + (bx - ax) * val;
	y2 = cy + (dy - cy) * val;
	x2 = cx + (dx - cx) * val;

	double ret = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

	return ret;
}

void solve() {
	double start = 0, end = 1;
	while (1) {
		double mid = (start + end) / 2;
		if (calSlope(mid) > 0) {
			end = mid;
		}
		else {
			start = mid;
		}

		if (abs(calDistance(start) - calDistance(end)) < e) {
			ans = calDistance(start);
			return;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	ans = LINF;
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

	solve();

	cout << fixed;
	cout.precision(10);
	cout << sqrt(ans);

	return 0;
}
