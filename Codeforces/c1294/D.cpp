#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define MAXHALF 500000000
using namespace std;

ll Q, X, Y, ans, cur;
vector<int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> Q >> X;
	m.resize(X, 0);
	for (ll t = 0; t < Q; t++) {
		cin >> Y;
		m[Y%X]++;
		while (m[cur]) {
			m[cur]--;
			ans++;
			cur = (cur + 1) % X;
		}
		cout << ans << '\n';
	}

	return 0;
}
