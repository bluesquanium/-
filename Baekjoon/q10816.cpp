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

ll N, M, t, ans;
unordered_map<ll, ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (m.count(t)) {
			m[t]++;
		}
		else {
			m[t] = 1;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> t;
		cout << m[t] << ' ';
	}

	return 0;
}
