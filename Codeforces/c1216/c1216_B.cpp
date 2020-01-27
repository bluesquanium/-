#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, M, ans, t;
vector<pii> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> t;
		m[i] = { t, i+1 };
	}
	sort(m.rbegin(), m.rend());
	for (int i = 0; i < m.size(); i++) {
		ans += i * m[i].first + 1;
	}

	cout << ans << '\n';
	for (int i = 0; i < N; i++) {
		cout << m[i].second << ' ';
	}

	return 0;
}
