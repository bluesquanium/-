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

ll T, N, K, ans;
vector<ll> m;
vector<ll> ks, biggers;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		ks.clear(); biggers.clear();
		cin >> N >> K;
		m.clear(); m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (m[i] == K) {
				ks.push_back(i);
			}
			else if (m[i] > K) {
				biggers.push_back(i);
			}
		}

		for (ll i = 0; i < ks.size(); i++) {
			for (ll j = ks[i] - 2; j <= ks[i] + 2; j++) {
				if (0 <= j && j < N && ks[i] != j) {
					if (m[j] >= K) {
						ans = 1;
						break;
					}
				}
			}
		}

		if (ks.size() > 0) {
			if (N == 1 || (N == 2 && biggers.size() > 0)) {
				ans = 1;
			}
			for (ll i = 1; i < biggers.size(); i++) {
				if (abs(biggers[i - 1] - biggers[i]) <= 2) {
					ans = 1;
					break;
				}
			}
		}

		if (ans) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}

	return 0;
}
