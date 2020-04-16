#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

enum {
	Min=0, Max=1
};

int N, ans;
int x[10][2], y[10][2];
vector<string> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (int color = 1; color < 10; color++) {
		x[color][Min] = 999;
		x[color][Max] = -1;
		y[color][Min] = 999;
		y[color][Max] = -1;
	}
	for (int i = 0; i < N; i++) {
		cin >> m[i];
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int color = m[i][j] - '0';
			if (i < y[color][Min]) {
				y[color][Min] = i;
			}
			if (i > y[color][Max]) {
				y[color][Max] = i;
			}
			if (j < x[color][Min]) {
				x[color][Min] = j;
			}
			if (j > x[color][Max]) {
				x[color][Max] = j;
			}
		}
	}

	for (int color = 1; color < 10; color++) {
		if (y[color][Max] == -1) {
			continue;
		}
		int check = 1;
		for (int i = y[color][Min]; i <= y[color][Max]; i++) {
			for (int j = x[color][Min]; j <= x[color][Max]; j++) {
				if (m[i][j] - '0' == color) {
					for (int anotherColor = 1; anotherColor < 10; anotherColor++) {
						if (anotherColor == color) {
							continue;
						}
						if (y[anotherColor][Min] <= i && i <= y[anotherColor][Max] &&
							x[anotherColor][Min] <= j && j <= x[anotherColor][Max]) {
							check = 0;
							break;
						}
					}
				}

				if (check == 0) {
					break;
				}
			}
			if (check == 0) {
				break;
			}
		}
		ans += check;
	}

	cout << ans;

	return 0;
}
