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

ll T, K, temp;
vector<ll> ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> K;
		if (K % 2 == 1) {
			cout << "-1" << '\n';
		}
		else {
			ans.clear();
			while (K != 0) {
				ll val = 2, cnt = 0;
				for (ll i = 3; i <= 20; i++) {
					if (val < K) {
						val *= i;
						cnt++;
					}
					else {
						if (val > K) {
							val /= i - 1;
							cnt--;
						}
						break;
					}
				}
				if (val > K) {
					val /= 20;
					cnt--;
				}
				K -= val;
				ans.push_back(1);
				for (ll i = 0; i < cnt; i++) {
					ans.push_back(0);
				}
			}
			cout << ans.size() << '\n';
			for (ll i = 0; i < ans.size(); i++) {
				cout << ans[i] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}
