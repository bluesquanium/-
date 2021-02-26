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

ll N, M, ans, temp;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> s;

	ll cnt = 0;
	char prev = '\0';
	for (ll i = 0; i < s.size(); i++) {
		char cur = s[i];
		if (prev == '(') {
			if (cur == '(') {
				cnt++;
				ans++;
			}
			else {
				// lazor
				ans += cnt;
			}
		}
		else {
			if (cur == ')') {
				cnt--;
			}
		}

		prev = cur;
	}

	cout << ans;

	return 0;
}
