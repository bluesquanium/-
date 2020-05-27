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

ll L, C, ans;
vector<char> alpha;
char pass[15];

ll isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return 1;
	}
	return 0;
}

void solve(ll cnt, ll cur, ll vowel, ll consonant) {
	if (cnt == L) {
		if (vowel >= 1 && consonant >= 2) {
			for (ll i = 0; i < L; i++) {
				cout << pass[i];
			}
			cout << '\n';
		}
		return;
	}

	for (ll i = cur; i < C; i++) {
		pass[cnt] = alpha[i];
		solve(cnt + 1, i + 1, vowel + isVowel(alpha[i]), consonant + !isVowel(alpha[i]));
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> L >> C;
	alpha.resize(C);
	for (ll i = 0; i < C; i++) {
		cin >> alpha[i];
	}
	sort(alpha.begin(), alpha.end());

	solve(0, 0, 0, 0);

	return 0;
}
