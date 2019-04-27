#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int t[4] = { 'A', 'C', 'T', 'G' };

int N, ans = 1000;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	cin >> s;

	for (int i = 0; i < s.size()-3; i++) {
		int count = 0;
		for (int j = i; j < i+4; j++) {
			count += min(abs(s[j] - t[j - i]), 26 - abs(s[j] - t[j - i]));
		}
		ans = min(ans, count);
	}

	cout << ans;

	return 0;
}
