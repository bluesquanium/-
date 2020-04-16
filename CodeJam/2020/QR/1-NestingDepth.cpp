#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll T, cur;
string s, ans;
vector<char> st;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ans.clear();
		st.clear();
		cin >> s;

		cur = 0;
		for (int i = 0; i < int(s.size()); i++) {
			ll num = s[i] - '0';
			if (num - cur >= 0) {
				for (int j = 0; j < num - cur; j++) {
					ans.push_back('(');
				}
				ans.push_back(s[i]);
			}
			else {
				for (int j = 0; j < cur - num; j++) {
					ans.push_back(')');
				}
				ans.push_back(s[i]);
			}
			cur = num;
		}
		for (int i = 0; i < cur; i++) {
			ans.push_back(')');
		}

		cout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}
