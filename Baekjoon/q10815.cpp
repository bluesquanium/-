#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll N, M, t;
unordered_map<ll, ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> t;
		m[t] = 1;
	}
	cin >> M;
	for (ll i = 0; i < M; i++) {
		cin >> t;
		if (m.count(t)) {
			cout << 1 << ' ';
		}
		else {
			cout << 0 << ' ';
		}
	}

	return 0;
}
