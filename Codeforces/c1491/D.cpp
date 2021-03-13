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

ll Q, ans, temp;
vector<pll> m;

ll cnt1(string a) {
	ll ret = 0;
	for (ll i = 0; i < a.size(); i++) {
		if (a[i] == '1') {
			ret++;
		}
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> Q;
	m.resize(Q);
	for (ll i = 0; i < Q; i++) {
		ans = 0;
		cin >> m[i].first >> m[i].second;

		if (m[i].first <= m[i].second) {
			string a, b;
			ll num = m[i].first;
			while (num) {
				if (num % 2 == 0) {
					a.push_back('0');
				}
				else {
					a.push_back('1');
				}
				num /= 2;
			}
			num = m[i].second;
			while (num) {
				if (num % 2 == 0) {
					b.push_back('0');
				}
				else {
					b.push_back('1');
				}
				num /= 2;
			}

			if (cnt1(a) >= cnt1(b)) {
				ll curA = a.size() - 1;
				ll curB = b.size() - 1;

				ans = 1;
				for (; curB >= 0; curB--) {
					if (b[curB] == '1') {
						bool isFail = true;
						for (; curA >= 0; curA--) {
							if (a[curA] == '1' && curB >= curA) {
								isFail = false;
								curA--;
								break;
							}
						}

						if (isFail == true) {
							ans = 0;
							break;
						}
					}
				}
			}
		}

		if (ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
