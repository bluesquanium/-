#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;
vector<int> a, b, c;
multiset<int> m;

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
		m.insert(b[i]);
	}

	for (int i = 0; i < N; i++) {
		int cur = N - a[i];
		auto iter = m.lower_bound(cur);
		if (iter == m.end()) {
			iter = m.begin();
		}
		c[i] = (a[i] + (*iter)) % N;
		m.erase(iter);
	}

	for (int i = 0; i < N; i++) {
		cout << c[i] << ' ';
	}

	return 0;
}
