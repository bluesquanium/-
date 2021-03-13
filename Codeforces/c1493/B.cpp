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

ll T, H, M, ans, temp;

bool hasInvalidNum(ll num) {
	while (num) {
		ll digit = num % 10;
		if (digit == 3 || digit == 4 || digit == 6 || digit == 7 || digit == 9) {
			return true;
		}
		num /= 10;
	}
	return false;
}

ll reflectNum(ll num) {
	ll ret = 0;
	for(ll i = 0; i < 2; i++) {
		ret *= 10;

		ll digit = num % 10;
		switch (digit) {
		case 0:
			ret += 0;
			break;
		case 1:
			ret += 1;
			break;
		case 2:
			ret += 5;
			break;
		case 5:
			ret += 2;
			break;
		case 8:
			ret += 8;
			break;
		}

		num /= 10;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		string s;
		cin >> H >> M;
		cin >> s;
		ll h = 0, m = 0;
		for (ll i = 0; i < 2; i++) {
			h *= 10;
			h += s[i] - '0';
		}
		for (ll i = 3; i < 5; i++) {
			m *= 10;
			m += s[i] - '0';
		}

		while (1) {
			if (m >= M) {
				m = 0;
				h++;
			}
			if (h >= H) {
				h = 0;
			}

			if (!hasInvalidNum(m) && !hasInvalidNum(h)) {
				ll rh = reflectNum(m);
				ll rm = reflectNum(h);
				if (rh < H && rm < M) {
					if (h < 10) {
						cout << 0;
					}
					cout << h;
					cout << ':';
					if (m < 10) {
						cout << 0;
					}
					cout << m << '\n';
					break;
				}
			}

			m++;
		}
	}

	return 0;
}
