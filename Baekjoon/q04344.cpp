#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int T, N;
double ans;
vector<int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++) {
		ans = 0;
		cin >> N;
		m.clear();
		m.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> m[i];
			ans += m[i];
		}
		ans /= N;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (m[i] > ans) {
				cnt++;
			}
		}

		printf("%.3lf%%\n", (double)cnt / N * 100);
	}

	return 0;
}
