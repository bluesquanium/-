#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;
vector<int> a, b, c;
map<int, int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	a.resize(N); b.resize(N); c.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> b[i];
		if (m.count(b[i]) == 0) {
			m[b[i]] = 1;
		}
		else {
			m[b[i]]++;
		}
	}
	sort(b.begin(), b.end());

	for (int i = 0; i < N; i++) {
		//c[i] = (a[i] + b[i]) % N;

		int cur = N - a[i];
		auto iter = m.lower_bound(cur);
		if (iter == m.end()) {
			iter = m.begin();
		}
		c[i] = (a[i] + (*iter).first) % N;
		(*iter).second -= 1;
		if ((*iter).second == 0) {
			m.erase(iter);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << c[i] << ' ';
	}

	return 0;
}
