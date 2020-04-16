#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, X, Y, ans;
vector<pii> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i].first >> m[i].second;
	}
	for (int i = 0; i < N; i++) {
		int my = 0, mx = 0;
		for (int j = 0; j < N; j++) {
			if (i == j) {
				continue;
			}
			if (m[i].first == m[j].first) {
				if (my < abs(m[i].second - m[j].second)) {
					my = abs(m[i].second - m[j].second);
				}
			}
			if (m[i].second == m[j].second) {
				if (mx < abs(m[i].first - m[j].first)) {
					mx = abs(m[i].first - m[j].first);
				}
			}
		}

		if (ans < mx * my) {
			ans = mx * my;
		}
	}

	cout << ans;

	return 0;
}
