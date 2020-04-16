#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
using namespace std;

int N, ans;
set<string> s;
vector<string> m;
string temp;

bool cmp(string s1, string s2) {
	int loop = min(s1.size(), s2.size());

	if (s1.size() != s2.size()) {
		if (s1.size() < s2.size()) {
			return 1; // ??
		}
		else {
			return 0;
		}
	}
	for (int i = 0; i < loop; i++) {
		if (s1[i] < s2[i]) {
			return 1;
		}
		else if (s1[i] > s2[i]) {
			return 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		s.insert(temp);
	}
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		m.push_back(*iter);
	}
	sort(m.begin(), m.end(), cmp);

	for (int i = 0; i < m.size(); i++) {
		cout << m[i] << '\n';
	}
	return 0;
}
