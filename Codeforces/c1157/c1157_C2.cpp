#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int N, ans, cur;
deque<int> m;
vector<char> cmd;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i];
	}

	while (!m.empty()) {
		if ((int)m.front() < (int)m.back()) {
			if (cur < m.front()) {
				cur = m.front();
				m.pop_front();
				cmd.push_back('L');

				ans++;
			}
			else if (cur < m.back()) {
				cur = m.back();
				m.pop_back();
				cmd.push_back('R');

				ans++;
			}
			else {
				break;
			}
		}
		else if (m.front() > m.back()) {
			if (cur < m.back()) {
				cur = m.back();
				m.pop_back();
				cmd.push_back('R');

				ans++;
			}
			else if (cur < m.front()) {
				cur = m.front();
				m.pop_front();
				cmd.push_back('L');

				ans++;
			}
			else {
				break;
			}
		}
		else { // front == back
			int c = cur, count1 = 0, count2 = 0;
			vector<char> cmd1, cmd2;
			for (int i = 0; i < m.size(); i++) {
				if (c < m[i]) {
					c = m[i];
					cmd1.push_back('L');
					
					count1++;
				}
				else {
					break;
				}
			}
			c = cur;
			for (int i = m.size()-1; i >= 0; i--) {
				if (c < m[i]) {
					c = m[i];
					cmd2.push_back('R');

					count2++;
				}
				else {
					break;
				}
			}

			if (count1 >= count2) {
				ans += count1;
				for (int i = 0; i < cmd1.size(); i++) {
					cmd.push_back(cmd1[i]);
				}
			}
			else {
				ans += count2;
				for (int i = 0; i < cmd2.size(); i++) {
					cmd.push_back(cmd2[i]);
				}
			}
			break;
		}
	}

	cout << ans << '\n';
	for (int i = 0; i < cmd.size(); i++) {
		cout << cmd[i];
	}

	return 0;
}
