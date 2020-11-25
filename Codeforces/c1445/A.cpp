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
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll T, N, X, ans, temp;
vector<ll> a, b;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> X;
		a.clear(); a.resize(N);
		b.clear(); b.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for (ll i = 0; i < N; i++) {
			cin >> b[i];
		}
		sort(b.rbegin(), b.rend());

		ans = 1;
		for (ll i = 0; i < N; i++) {
			if (a[i] + b[i] > X) {
				ans = 0;
				break;
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
