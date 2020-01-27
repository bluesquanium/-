#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, ans;
int dict[26];
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	memset(dict, -1, sizeof(int) * 26);
	cin >> s;
	N = s.size();
	for (int i = 0; i < N; i++) {
		if (dict[s[i] - 'a'] == -1) {
			dict[s[i] - 'a'] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << dict[i] << ' ';
	}

	return 0;
}
