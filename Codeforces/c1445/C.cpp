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

ll T, P, Q, ans, temp;

vector<ll> targets;
void findPrimeFactors(ll n) {
	targets.clear();
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ll pf = 1;
			while (n != 0 && n % i == 0) {
				n /= i;
				pf *= i;
			}
			//pfs.push_back({ pf, cnt });

			ll pf2 = 1, p = P;
			while (p != 0 && p % i == 0) {
				p /= i;
				pf2 *= i;
			}

			targets.push_back(pf2 / pf * i);
		}
	}
	if (n > 1) {
		ll pf = n, pf2 = 1;
		ll p = P;
		while (p != 0 && p % n == 0) {
			p /= n;
			pf2 *= n;
		}

		//pfs.push_back(n);

		targets.push_back(pf2 / pf * n);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> P >> Q;

		if (P < Q || P % Q != 0) {
			ans = P;
		}
		else {
			// q를 소인수 분해
			findPrimeFactors(Q);

			// 소트
			sort(targets.begin(), targets.end());
			ans = P / targets[0];

		}

		cout << ans << '\n';
	}

	return 0;
}
