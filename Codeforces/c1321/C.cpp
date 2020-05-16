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

#define NUMALPHA 26

ll N, ans;
string s;

bool Removable(ll idx) {
	if (0 <= idx - 1 && s[idx - 1] + 1 == s[idx]) {
		return true;
	}
	if (idx + 1 < s.size() && s[idx + 1] + 1 == s[idx]) {
		return true;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	cin >> s;

	for (ll i = NUMALPHA - 1; i >= 0; i--) {
		for (ll j = 0; j < s.size(); j++) {
			if (s[j] == 'a' + i) {
				if (Removable(j)) {
					s.erase(j, 1);
					j--;
					ans++;
				}
			}
		}
		for (ll j = s.size() - 1; j >= 0; j--) {
			if (s[j] == 'a' + i) {
				if (Removable(j)) {
					s.erase(j, 1);
					ans++;
				}
			}
		}
	}

	cout << ans;

	return 0;
}
