#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, ans;
set<int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;

	while (m.count(N) == 0) {
		m.insert(N);
		ans++;
		N++;
		while (N == N / 10 * 10) {
			N /= 10;
		}
	}

	cout << ans;

	return 0;
}
