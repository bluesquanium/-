#include <iostream>
#include <vector>
#include <algorithm>
#define ll	long long
using namespace std;

ll fac(ll a) {
	if (a <= 1) {
		return 1;
	}
	return a * fac(a - 1);
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<int> v;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}

	ll c = 0;
	do {
		if (c % fac(n-m) == 0) {
			for (int i = 0; i < m; i++) {
				cout << v[i] << ' ';
			} cout << '\n';
		}
		c++;
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}
