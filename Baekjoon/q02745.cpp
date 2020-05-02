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

ll b, ans;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> s >> b;
	for (ll i = 0; i < s.size(); i++) {
		ans *= b;
		if ('0' <= s[i] && s[i] <= '9') {
			ans += s[i] - '0';
		}
		else {
			ans += s[i] - 'A' + 10;
		}
	}

	cout << ans;

	return 0;
}
