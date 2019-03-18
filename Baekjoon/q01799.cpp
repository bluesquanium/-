#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans;
bool m[10][10];
bool l_dia[20], r_dia[20]; // r_dia는 10 더해서.

void Dfs(int cur, int count) {
	if (cur < 2*N) {
		int i, j;
		if (cur < N) {
			i = 0;
			j = cur;
		}
		else {
			i = cur + 1 - N;
			j = N - 1;
		}
		bool check = false;
		while (0 <= j && i < N) {
			if (m[i][j]) {
				if (r_dia[i - j + 10] == 0) {
					check = true;
					r_dia[i - j + 10] = 1;
					Dfs(cur + 1, count + 1);
					r_dia[i - j + 10] = 0;
				}
			}

			i++;
			j--;
		}
		if (check == 0) {
			Dfs(cur + 1, count);
		}
	}
	ans = max(ans, count);

	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
		}
	}

	Dfs(0, 0);

	cout << ans;
	return 0;
}
