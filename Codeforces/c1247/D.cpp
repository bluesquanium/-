#include <iostream>
#include <vector>
#include <algorithm>
#define ll	long long
#define MAX	10000000000
using namespace std;

ll N, K, ans, xk;
vector<ll> m;
int p1, p2;

ll calxk(ll x, ll k) {
	ll num = 1;
	while (k--) {
		num *= x;
		if (num > MAX) {
			return -1;
		}
	}
	return num;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i];
	}
	sort(m.begin(), m.end());
	ll i = 1, base = 0;
	while ((xk = calxk(i, K)) != -1) {
		p2 = N - 1;
		while (base <= N - 2 && m[base] * m[p2] < xk) base++;
		p1 = base;
		while (p1 != p2) {
			if (m[p1] * m[p2] > xk) {
				p2--;
			}
			else if (m[p1] * m[p2] < xk) {
				p1++;
			}
			else {
				ans++;
				if (m[p1] == m[p2]) {
					ans--;
					ans += (p2 - p1 + 1) * (p2 - p1) / 2;
					break;
				}
				else if (m[p1] == m[p1 + 1] && m[p2] == m[p2 - 1]) {
					ans--;
					int n1 = 1, n2 = 1;
					while (m[p1] == m[p1 + 1]) {
						p1++;
						n1++;
					}
					p1++;
					while (m[p2] == m[p2 - 1]) {
						p2--;
						n2++;
					}
					//p2--;
					ans += n1 * n2;
				}
				else if (m[p1] == m[p1 + 1]) p1++;
				else if (m[p2] == m[p2 - 1]) p2--;
				else {
					p1++;
				}
			}
		}

		i++;
	}




	cout << ans;

	return 0;
}
