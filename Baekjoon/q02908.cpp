#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int T, N, ans;
int num[2];
string s[2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> s[0] >> s[1];
	for (int i = s[0].size() - 1; i >= 0; i--) {
		num[0] *= 10;
		num[0] += s[0][i] - '0';
	}
	for (int i = s[1].size() - 1; i >= 0; i--) {
		num[1] *= 10;
		num[1] += s[1][i] - '0';
	}

	ans = num[0] > num[1] ? num[0] : num[1];

	cout << ans;

	return 0;
}
