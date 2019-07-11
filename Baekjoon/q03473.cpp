#include <iostream>
#include <vector>
#include <string>
#include <utility>
#define pii	pair<int,int>
using namespace std;

int T;
string s, ANS;
vector<pii> pp;

int getPriority(char c) {
	switch (c) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '(':
		return 0;
	case ')':
		return -1;
	default:
		return -999;
	}
}

string algorithm(string s) {
	string ans;
	vector<char> st;

	for (auto cur = 0; cur < s.size(); cur++) {
		if (s[cur] == '.') {
			continue;
		}
		else if ( ('A' <= s[cur] && s[cur] <= 'Z') ||
				  ('a' <= s[cur] && s[cur] <= 'z') ) {
			ans += s[cur];
		}
		else {
			int curP = getPriority(s[cur]);
			if (curP >= 0) { // +- */ (
				if (st.empty() || s[cur] == '('
					|| getPriority(st.back()) < curP) {
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
					exit(-1); // 종료
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
			exit(-1);
		}
		ans += st.back();
		st.pop_back();
	}

	//cout << ans << '\n'; //////

	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;

	while (T--) {
		//cout << "#" << T << '\n'; ///////

		s.clear(); ANS.clear();
		pp.clear();

		cin >> s; // 입력에 공백 있으면 안됨.

		vector<int> temp_st;
		for (int cur = 0; cur < s.size(); cur++) { // 괄호쌍 찾기
			if (s[cur] == '(') {
				temp_st.push_back(cur);
			}
			else if (s[cur] == ')') {
				pp.push_back({ temp_st.back(), cur });
				temp_st.pop_back();
			}
		}

		ANS = algorithm(s);
		for (auto i = 0; i < pp.size(); i++) {
			pii cur = pp[i];
			string temp_s = s;
			temp_s[cur.first] = '.';
			temp_s[cur.second] = '.';
			if (ANS == algorithm(temp_s)) {
				s[cur.first] = '.';
				s[cur.second] = '.';
			}
			else {
				int left = cur.first, right = cur.second;
				while (0 <= left - 1 && s[left - 1] == '.') {
					left--;
				}
				while (right + 1 < (int)(s.size()) - 1 && s[right + 1] == '.') {
					right++;
				}

				if (0 <= left - 1 && s[left - 1] == '+') { // + : 뒤에랑 등급 같을 경우 ( 또는 뒤에 아무것도 없을 경우 )
					if (right == (int)(s.size()) - 1 || s[right + 1] == ')' || getPriority(s[right + 1]) == getPriority('+')) {
						s[cur.first] = '.';
						s[cur.second] = '.';
						ANS = algorithm(s);
					}
				}
				else if (0 <= left - 1 && s[left - 1] == '*') { // * : 괄호 안과 등급 같을 경우
					bool check = true;
					temp_st.clear();
					for (int j = cur.first+1; j < cur.second; j++) {
						if (s[j] == '(') {
							temp_st.push_back(s[j]);
						}
						else if (s[j] == ')') {
							temp_st.pop_back();
						}
						else if ( s[j] == '*' || s[j] == '/' || s[j] == '+' || s[j] == '-' ) {
							if (temp_st.empty()) {
								if (s[j] == '+' || s[j] == '-') {
									check = false;
									break;
								}
							}
						}
					}
					if (check) {
						s[cur.first] = '.';
						s[cur.second] = '.';
						ANS = algorithm(s);
					}
				}
			}
		}

		for (int i = 0; i < s.size(); i++) {
			if (s[i] != '.') {
				cout << s[i];
			}
		}cout << '\n';
	}

	return 0;
}
