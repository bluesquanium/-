#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
int T, ans;
vector<char> st;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		ans = 1;
		st.clear();
		cin >> s;
		for (auto i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				st.push_back('(');
			}
			else if(s[i] == ')') {
				if (!st.empty()) {
					st.pop_back();
				}
				else {
					ans = 0;
					break;
				}
			}
			else {
				ans = 0;
				break;
			}
		}
		if (!st.empty()) {
			ans = 0;
		}

		if (ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
