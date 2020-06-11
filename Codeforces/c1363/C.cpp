#include <iostream>
#include <cmath>
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

ll T, N, X, ans;
vector<pll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> X;
		m.clear(); m.resize(N);
		ll cnt = 0;
		for (ll i = 0; i < N - 1; i++) {
			cin >> m[i].first >> m[i].second;
			if (m[i].first == X || m[i].second == X) {
				cnt++;
			}
		}

		if (cnt <= 1) {
			cout << "Ayush\n";
		}
		else {
			if (N % 2 == 0) {
				cout << "Ayush\n";
			}
			else {
				cout << "Ashish\n";
			}
		}
	}

	return 0;
}
