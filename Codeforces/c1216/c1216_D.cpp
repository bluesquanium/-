#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll N, M, g, maxi;
ll y;
vector<ll> m;

ll gcd(ll x, ll y) {
	return y ? gcd(y, x%y) : x;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i];
		maxi = max(maxi, m[i]);
	}

	sort(m.begin(), m.end());
	g = maxi - m[0];
	for (int i = 0; i < N; i++) {
		g = gcd(g, maxi - m[i]);
	}

	for (int i = 0; i < N; i++) {
		y += (maxi - m[i]) / g;
	}

	if (N == 2) {
		ll t = m[0] - m[1]; t = t > 0 ? t : -t;
		cout << "1 " << t;
	}
	else {
		cout << y << ' ' << g;
	}

	return 0;
}
