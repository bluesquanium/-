#include <iostream>
#include <vector>
#include <algorithm>
#define pii	pair<int,int>
using namespace std;

int N, a, ans;
vector<pii> m;

bool cmp(pii a, pii b) {
	return a.first > b.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;

	if (N < 6) {
		cout << 0;
		return 0;
	}

	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i].first >> m[i].second;
	}
	sort(m.begin(), m.end(), cmp);

	a = m[4].first;
	for (int i = 5; i < m.size(); i++) {
		if (m[i].first != a) {
			break;
		}
		ans++;
	}

	cout << ans;

	return 0;
}
