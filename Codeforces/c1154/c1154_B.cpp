#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, a, b, c;
vector<int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		m.push_back(a);
	}
	sort(m.begin(), m.end());
	a = m[0];
	for (int i = 0; i < N; i++) {
		if (m[i] == a || m[i] == b || m[i] == c) {
			continue;
		}

		if (b == 0) {
			b = m[i];
		}
		else if(c == 0) {
			c = m[i];
		}
		else {
			c = 99999;
			break;
		}
	}

	if (b == 0) {
		cout << 0;
	}
	else if (c != 0) {
		if (c - b == b - a) {
			cout << c - b;
		}
		else {
			cout << -1;
		}
	}
	else {
		if ((b - a) % 2 == 0) {
			cout << (b - a) / 2;
		}
		else {
			cout << b - a;
		}
	}

	return 0;
}
