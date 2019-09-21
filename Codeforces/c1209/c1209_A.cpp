#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans;
vector<int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i];
	}
	sort(m.begin(), m.end());

	for (int i = 0; i < N; i++) {
		if (m[i] != 0) {
			ans++;
			int d = m[i];
			for (int j = i + 1; j < N; j++) {
				if (m[j] != 0 && (m[j] % d) == 0) {
					m[j] = 0;
				}
			}
		}
	}

	cout << ans;

	return 0;
}
