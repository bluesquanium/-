#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, M, ans, a, b;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> s;

	for (int i = 0; i < N; i += 2) {
		if (s[i] == s[i + 1]) {
			if (s[i + 1] == 'a') {
				s[i + 1] = 'b';
			}
			else {
				s[i + 1] = 'a';
			}
			ans++;
		}
	}

	cout << ans << '\n' << s;

	return 0;
}
