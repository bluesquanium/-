#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll T, N, K;
vector<ll> a, ans_arr;
set<ll> c;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans_arr.clear();
		c.clear();
		cin >> N >> K;
		a.clear(); a.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> a[i];
			c.insert(a[i]);
		}

		if (c.size() > K) {
			cout << "-1\n";
		}
		else {
			vector<ll> cycle1;
			for (auto iter = c.begin(); iter != c.end(); iter++) {
				cycle1.push_back(*iter);
			}
			for (ll i = cycle1.size(); i < K; i++) {
				cycle1.push_back(*c.begin());
			}

			cout << N * cycle1.size() << '\n';

			for (ll i = 0; i < N; i++) {
				for (ll j = 0; j < cycle1.size(); j++) {
					cout << cycle1[j] << ' ';
				}
			}
			cout << '\n';
		}
	}

	return 0;
}
