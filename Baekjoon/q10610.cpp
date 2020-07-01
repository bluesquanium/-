#include <iostream>
#include <cmath>
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

string s;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> s;

	ll sum = 0, have0 = false;
	for (ll i = 0; i < s.size(); i++) {
		m.push_back(s[i] - '0');
		sum += m.back();
		have0 = have0 || m.back() == 0;
	}

	if (have0 && sum % 3 == 0) {
		sort(m.rbegin(), m.rend());
		for (ll i = 0; i < m.size(); i++) {
			cout << m[i];
		}
	}
	else {
		cout << -1;
	}

	return 0;
}
