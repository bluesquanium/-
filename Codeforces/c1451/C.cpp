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

ll T, N, K, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		vector<ll> dict(26, 0), target(26, 0);
		cin >> N >> K;
		string a, b;
		cin >> a;
		cin >> b;
		for (ll i = 0; i < N; i++) {
			dict[a[i] - 'a']++;
		}
		for (ll i = 0; i < N; i++) {
			target[b[i] - 'a']++;
		}
		ans = 1;
		for (ll alpha = 0; alpha < 26 - 1; alpha++) {
			if (target[alpha] > dict[alpha]) {
				ans = 0;
				break;
			}
			else if (target[alpha] < dict[alpha]) {
				if ((dict[alpha] - target[alpha]) % K == 0) {
					dict[alpha + 1] += dict[alpha] - target[alpha];
				}
				else {
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
