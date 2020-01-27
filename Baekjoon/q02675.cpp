#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int T, R, ans;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> R >> s;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < R; j++) {
				cout << s[i];
			}
		}
		cout << '\n';
	}

	return 0;
}
