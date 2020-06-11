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

ll T, N, M, ans;
ll c[2];
vector<ll> a, b;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 1;
		c[0] = c[1] = 0;
		cin >> N;
		a.clear(); a.resize(N);
		b.clear(); b.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> a[i];
		}
		for (ll i = 0; i < N; i++) {
			cin >> b[i];
			c[b[i]]++;
		}

		if (c[0] == 0 || c[1] == 0) {
			for (ll i = 1; i < N; i++) {
				if (a[i - 1] > a[i]) {
					ans = 0;
					break;
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
