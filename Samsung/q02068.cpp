#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int m, temp;
		cin >> m;
		for (int i = 0; i < 9; i++) {
			cin >> temp;
			m = max(m, temp);
		}

		cout << '#' << t << ' ' << m << '\n';
	}

	return 0;
}
