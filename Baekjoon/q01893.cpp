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

ll N, M, temp;
string A, W, S;
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

bool Kmp(string s, string pattern) {
	ll ret = 0;
	vector<ll> ff = GetFailFunction(pattern);

	ll j = 0;
	for (ll i = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != pattern[j]) {
			j = ff[j - 1];
		}

		if (s[i] == pattern[j]) {
			if (j == pattern.size() - 1) {
				j = ff[j];
				ret++;
				if (ret > 1) {
					return false;
				}
			}
			else {
				j++;
			}
		}
	}
	if (ret == 1) {
		return true;
	}
	return false;
}

ll idxA[50000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> A;
		cin >> W;
		cin >> S;

		ll dict[62];
		for (ll j = 0; j < A.size(); j++) {
			dict[j] = A[j];
		}
		for (ll j = 0; j < W.size(); j++) {
			for (ll k = 0; k < A.size(); k++) {
				if (W[j] == A[k]) {
					idxA[j] = k;
					break;
				}
			}
		}

		ans.clear();
		for (ll j = 0; j < A.size(); j++) {
			string s;
			for (ll k = 0; k < W.size(); k++) {
				idxA[k] = (idxA[k] + 1) % A.size();
				s.push_back(dict[idxA[k]]);
			}

			if (Kmp(S, s)) {
				ans.push_back((j + 1) % A.size());
			}
		}

		if (ans.size() == 0) {
			cout << "no solution\n";
		}
		else if (ans.size() == 1) {
			cout << "unique: " << ans[0] << '\n';
		}
		else {
			cout << "ambiguous: ";
			sort(ans.begin(), ans.end());
			for (ll j = 0; j < ans.size(); j++) {
				cout << ans[j] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}
