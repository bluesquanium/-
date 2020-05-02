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

ll T, N, M;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> s;
		ll check = s[0];
		for (ll i = 1; i < s.size(); i++) {
			if (check != s[i]) {
				check = 0;
			}
		}
		if (check != 0) {
			cout << s;
		}
		else {
			for (int i = 0; i < s.size(); i++) {
				cout << "01";
			}
		}
		cout << '\n';
	}

	return 0;
}
