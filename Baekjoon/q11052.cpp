#include <iostream>
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
vector<ll> mem;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	mem.resize(N + 1);
	for (ll i = 1; i <= N; i++) {
		cin >> mem[i];
	}

	for (ll i = 2; i <= N; i++) {
		for (ll j = 1; j <= i / 2; j++) {
			mem[i] = max(mem[i], mem[j] + mem[i - j]);
		}
	}

	cout << mem[N];

	return 0;
}
