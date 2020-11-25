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

string s, p;

vector<ll> GetFF(string s) {
	vector<ll> ff;
	ff.resize(s.size());

	ll j = 0;
	for (ll i = 1; i < ff.size(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = ff[j - 1];
		}

		if (s[j] == s[i]) {
			ff[i] = ++j;
		}
	}

	return ff;
}

bool Kmp(string s, string pattern) {
	vector<ll> ff = GetFF(pattern);

	ll j = 0;
	for (ll i = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != pattern[j]) {
			j = ff[j - 1];
		}

		if (s[i] == pattern[j]) {
			if (j == pattern.size() - 1) {
				return true;
			}
			j++;
		}
	}

	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> s;
	cin >> p;

	if (Kmp(s, p)) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}
