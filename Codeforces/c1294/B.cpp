#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int T, N;
pii cur;
vector<pii> m;
string s;

bool cmp(pii a, pii b) {
	return (a.first + a.second) < (b.first + b.second);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++) {
		bool check = true;
		m.clear();
		s.clear();
		cur.first = cur.second = 0;

		cin >> N;
		m.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> m[i].first >> m[i].second;
		}
		sort(m.begin(), m.end(), cmp);
		for (int i = 0; i < N; i++) {
			if (cur.first > m[i].first || cur.second > m[i].second) {
				check = false;
				break;
			}

			while (cur.first != m[i].first) {
				s += "R";
				cur.first++;
			}
			while (cur.second != m[i].second) {
				s += "U";
				cur.second++;
			}
			
			//cur.first = m[i].first;
			//cur.second = m[i].second;
		}

		if (check) {
			cout << "YES\n";
			cout << s << '\n';
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
