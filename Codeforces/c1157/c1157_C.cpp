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
		if ( (int)m.front() <= (int)m.back() ) {
			if (cur <= m.front()) {
				cur = m.front();
				m.pop_front();
				cmd.push_back('L');

				ans++;
			}
			else if (cur <= m.back()) {
				cur = m.back();
				m.pop_back();
				cmd.push_back('R');

				ans++;
			}
			else {
				break;
			}
		}
		else {
			if (cur <= m.back()) {
				cur = m.back();
				m.pop_back();
				cmd.push_back('R');

				ans++;
			}
			else if (cur <= m.front()) {
				cur = m.front();
				m.pop_front();
				cmd.push_back('L');

				ans++;
			}
			else {
				break;
			}
		}
	}

	cout << ans << '\n';
	for (int i = 0; i < cmd.size(); i++) {
		cout << cmd[i];
	}

	return 0;
}
