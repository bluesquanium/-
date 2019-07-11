#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
int ans;
vector<int> st;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (auto i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[') {
			st.push_back(s[i]);
		}
		else if (s[i] == ')' || s[i] == ']') {
			int temp = 0, tar, check = 1;
			if (s[i] == ')') {
				tar = '(';
			}
			else {
				tar = '[';
			}
			while (!st.empty()) {
				if (st.back() != tar &&
					st.back() >= 0) {
					check = 0;
					break;
				}
				if (st.back() == tar) {
					st.pop_back();
					if (temp == 0) temp = -1;
					if (tar == '[') {
						st.push_back(temp * 3);
					}
					else {
						st.push_back(temp * 2);
					}
					break;
				}
				temp += st.back();
				st.pop_back();
			}
			if (!check) {
				ans = 0;
				break;
			}
		}
		else {
			ans = 0;
			break;
		}
	}
	while (!st.empty()) {
		if (st.back() >= 0) {
			ans = 0;
			break;
		}
		ans += st.back();
		st.pop_back();
	}

	cout << -ans;

	return 0;
}
