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

string s, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> s;

	ans.push_back(s[0]);
	for (ll i = 1; i < s.size(); i++) {
		if (s[i] == '-') {
			ans.push_back(s[i + 1]);
		}
	}

	cout << ans;

	return 0;
}
