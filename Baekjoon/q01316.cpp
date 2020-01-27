#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int T, N, ans;
int dict[26];
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 26; i++) {
			dict[i] = -1;
		}
		cin >> s;
		N = s.size();
		bool check = 1;
		for (int i = 0; i < N; i++) {
			int tar = s[i] - 'a';
			if (dict[tar] != -1 && dict[tar] != i-1) {
				check = 0;
				break;
			}
			dict[tar] = i;
		}

		if (check) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}
