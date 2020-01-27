#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int ans;
vector<pii> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	m.resize(9);
	for (int i = 0; i < 9; i++) {
		m[i].second = i+1;
		cin >> m[i].first;
	}
	sort(m.begin(), m.end());
	cout << m.back().first << '\n';
	cout << m.back().second;

	return 0;
}
