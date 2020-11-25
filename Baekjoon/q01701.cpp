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

ll ans;
string s;

ll GetFailFunction(string s) {
	ll ret = 0;

	vector<ll> ff;
	ff.resize(s.size());
	ll j = 0;
	for (ll i = 1; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = ff[j - 1];
		}
		if (s[i] == s[j]) {
			ff[i] = ++j;
			ret = max(ret, j);
		}
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> s;

	for (ll i = 0; i < s.size(); i++) {
		ans = max(ans, GetFailFunction(s.substr(i)));
	}

	cout << ans;

	return 0;
}
