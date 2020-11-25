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

ll N, M, temp;
string T, P;
vector<ll> ans;

vector<ll> GetFailFunction(string s) {
	vector<ll> ff;
	ff.resize(s.size());
	ll j = 0;
	for (ll i = 1; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = ff[j - 1];
		}
		if (s[i] == s[j]) {
			ff[i] = ++j;
		}
	}

	return ff;
}

void Kmp(string s, string pattern) {
	vector<ll> ff = GetFailFunction(pattern);

	ll j = 0;
	for (ll i = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != pattern[j]) {
			j = ff[j - 1];
		}

		if (s[i] == pattern[j]) {
			if (j == pattern.size() - 1) {
				ans.push_back(i - pattern.size() + 1);
				j = ff[j];
			}
			else {
				j++;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	getline(cin, T);
	getline(cin, P);

	Kmp(T, P);

	cout << ans.size() << '\n';
	for (ll i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}
