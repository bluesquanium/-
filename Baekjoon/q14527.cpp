#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, ans;
vector<pii> m;

bool cmp(pii a, pii b) {
	return a.second < b.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i].first >> m[i].second;
	}
	sort(m.begin(), m.end(), cmp);

	int head = 0, tail = N - 1;
	while (head < tail) {
		ans = m[head].second + m[tail].second > ans ? m[head].second + m[tail].second : ans;
		int mini = m[head].first < m[tail].first ? m[head].first : m[tail].first;
		m[head].first -= mini;
		m[tail].first -= mini;
		if (m[head].first == 0) head++;
		if (m[tail].first == 0) tail--;
	}

	cout << ans;

	return 0;
}
