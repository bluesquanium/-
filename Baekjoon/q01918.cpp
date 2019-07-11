#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s, ans;
vector<char> st;

int getPriority(char c) {
	switch (c) {
	case '+' :
	case '-' :
		return 1;
	case '*' :
	case '/' :
		return 2;
	case '(' :
		return 0;
	case ')' :
		return -1;
	default :
		return -999;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> s; // 입력에 공백 있으면 안됨.

	for (auto cur = 0; cur < s.size(); cur++) {
		if (s[cur] == ' ') {
			continue;
		}
		else if ('A' <= s[cur] && s[cur] <= 'Z') {
			ans += s[cur];
		}
		else {
			int curP = getPriority(s[cur]);
			if (curP >= 0) { // +- */ (
				if (st.empty() || s[cur] == '('
					|| getPriority(st.back()) < curP ) {
					st.push_back(s[cur]);
				}
				else {
					while (!st.empty() && getPriority(st.back()) >= curP) {
						ans += st.back();
						st.pop_back();
					}
					st.push_back(s[cur]);
				}
			}
			else { // ) or default
				if (curP == -999) {
					cout << "ERR!";
					return -1;
				}
				else {
					while (!st.empty()) {
						if (st.back() == '(') {
							st.pop_back();
							break;
						}
						ans += st.back();
						st.pop_back();
					}
				}
			}
		}
	}
	while (!st.empty()) {
		if (st.back() == '(') {
			cout << "ERR!";
			return -1;
		}
		ans += st.back();
		st.pop_back();
	}

	cout << ans;

	return 0;
}
