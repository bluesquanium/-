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

ll T, N, X, ans, temp;
vector<ll> m;

int main(void) {
	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		cin >> N >> X;
		m.clear(); m.resize(N);
		ll allSame = 1, alreadyInfected = 0, sum = 0;
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			if (m[i] == X) {
				alreadyInfected = 1;
			}
			else {
				allSame = 0;
			}
			sum += m[i];
		}
		if (allSame == 1) {
			cout << 0 << '\n';
		}
		else if (sum == X * N || alreadyInfected == 1) {
			cout << 1 << '\n';
		}
		else {
			cout << 2 << '\n';
		}
	}

	return 0;
}
