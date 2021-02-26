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

ll T, N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;

	vector<ll> target;
	for (ll i = 3; i < 100000; i += 2) {
		target.push_back((i * i) / 2 + 1);
	}

	for (ll t = 1; t <= T; t++) {
		cin >> N;

		vector<ll>::iterator iter = upper_bound(target.begin(), target.end(), N);

		cout << iter - target.begin() << '\n';
	}

	return 0;
}
