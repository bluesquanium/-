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

ll T, N, ans, temp;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		ans = 0;
		cin >> N;
		cin >> s;
		ll startPoint = 0;
		for (ll i = 1; i < N; i++) {
			if (s[startPoint] != s[i]) {
				startPoint = i;
				break;
			}
		}
		
		if (startPoint) {
			char cur = s[startPoint];
			ll subSize = 1;
			for (ll i = startPoint + 1; i != startPoint; i = (i + 1) % N) {
				if (cur != s[i]) {
					ans += subSize / 3;

					cur = s[i];
					subSize = 0;
				}
				subSize++;
			}
			ans += subSize / 3;
		}
		else {
			ans = 1 + (N - 1) / 3;
		}

		cout << ans << '\n';
	}

	return 0;
}
