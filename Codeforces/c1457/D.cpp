#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

#define NMAX 100000

ll N, M, ans, temp;
vector<ll> m;
ll mem[NMAX + 1];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		mem[i + 1] = mem[i] ^ m[i];
	}

	ans = INF;
	for (ll l = 3; l <= N; l++) {
		for (ll i = 0, j = l; j <= N; i++, j++) {
			for (ll k = i + 1; k < j; k++) {
				if ((mem[i] ^ mem[k]) > (mem[k] ^ mem[j])) {
					cout << l - 2 << '\n';
					exit(0);
				}
			}
		}
	}

	cout << -1;

	return 0;
}
