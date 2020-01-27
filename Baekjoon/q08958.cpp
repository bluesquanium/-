#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, ans;
vector<string> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		ans = 0;
		cin >> m[i];
		int combo = 0;
		for (int j = 0; j < m[i].size(); j++) {
			if (m[i][j] == 'O') {
				combo++;
				ans += combo;
			}
			else {
				combo = 0;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
