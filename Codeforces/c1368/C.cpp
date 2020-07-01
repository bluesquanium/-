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

ll N, M, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	
	cout << 4 + 3 * N << '\n';
	cout << 0 << ' ' << 0 << '\n';
	cout << 0 << ' ' << 1 << '\n';
	cout << 1 << ' ' << 0 << '\n';
	cout << 1 << ' ' << 1 << '\n';
	cout << 1 << ' ' << 2 << '\n';
	ll depth = 2, base = 1, step = N - 1;
	for (ll i = 0; i < step; i++) {
		for (ll j = 0; j < 3; j++) {
			cout << depth << ' ' << base + j << '\n';
		}
		depth++; base++;
	}
	cout << depth << ' ' << base << '\n';
	cout << depth << ' ' << base + 1;


	return 0;
}
