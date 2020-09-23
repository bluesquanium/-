#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}
	sort(m.begin(), m.end());
	ll curSmall = 0, curBig = N / 2;

	cout << (N - 1) / 2 << '\n';
	for (ll i = 0; i < N / 2; i++) {
		cout << m[curBig++] << ' ';
		cout << m[curSmall++] << ' ';
	}
	if (N % 2 == 1) {
		cout << m[curBig];
	}

	return 0;
}
