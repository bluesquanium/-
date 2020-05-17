#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

const double pi = acos(-1);

ll T, N, M;
double ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N;

		double r2 = (double)1 / (double)(2 * (1 - cos(pi / N / 2)));
		ans = sqrt(r2);

		cout.precision(15);
		cout << ans << '\n';
	}

	return 0;
}
