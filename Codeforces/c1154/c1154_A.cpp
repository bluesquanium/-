#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> m;
int a, b, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		cin >> a;
		m.push_back(a);
	}
	sort(m.begin(), m.end());
	b = m.back();
	for (int i = 0; i < 3; i++) {
		cout << b - m[i] << ' ';
	}

	return 0;
}
