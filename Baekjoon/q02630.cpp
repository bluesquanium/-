#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, ans[2];
vector< vector<int> > m;

void solve(int n, int y, int x) {
	if (n > 0) {
		int tar = m[y][x];
		for (int i = y; i < y + n; i++) {
			for (int j = x; j < x + n; j++) {
				if (tar != m[i][j]) {
					solve(n / 2, y, x);
					solve(n / 2, y, x + n / 2);
					solve(n / 2, y + n / 2, x);
					solve(n / 2, y + n / 2, x + n / 2);
					return;
				}
			}
		}
		ans[tar]++;
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		m[i].resize(N);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
		}
	}

	solve(N, 0, 0);

	cout << ans[0] << '\n';
	cout << ans[1] << '\n';

	return 0;
}

