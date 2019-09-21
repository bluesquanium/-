#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, Q, ans, ans2, e, t;
vector<int> m;
map<int,int> endpoint, c;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> Q;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i];
		endpoint[m[i]] = i;
		if (c.count(m[i]) == 0) {
			c[m[i]] = 1;
		}
		else {
			c[m[i]]++;
		}
	}
	/*
	for (int i = 0; i < Q; i++) {

	}
	*/

	for (int i = 0; i < N; i++) {
		int maxi = c[m[i]];
		ans += maxi;
		t = m[i];
		e = endpoint[t];
		while (i < e) {
			if (m[i] != t) {
				maxi = max(maxi, c[m[i]]);
				ans++;
				if (endpoint[m[i]] > e) {
					e = endpoint[m[i]];
					m[endpoint[m[i]]] = t;
					ans++;
				}
			}
			i++;
		}
		ans -= maxi;
	}

	cout << ans;

	return 0;
}
