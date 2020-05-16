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

ll T, A, K, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> A >> K;
		for(ll i = 1; i < K; i++) {
			ll mini = A % 10, maxi = A % 10;
			ll num = A / 10;
			while (num) {
				mini = min(mini, num % 10);
				maxi = max(maxi, num % 10);
				num /= 10;
			}
			A += mini * maxi;
			if (mini * maxi == 0) {
				break;
			}
		}

		cout << A << '\n';
	}

	return 0;
}
