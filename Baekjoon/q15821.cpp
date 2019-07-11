#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#define ll	long long
using namespace std;

int N, K, Pi, c;
ll x, y;
priority_queue<ll, vector<ll>> m;

ll dist(ll x, ll y) {
	return x*x + y*y;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> Pi;
		ll r = 0;
		for (int j = 0; j < Pi; j++) {
			cin >> x >> y;
			r = max(r, dist(x, y));
		}

		if (c < K) {
			c++;
			m.push(r);
		}
		else {
			if (m.top() > r) {
				m.pop(); m.push(r);
			}
		}
	}

	cout << m.top() << ".00";

	return 0;
}
