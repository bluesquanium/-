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
vector<ll> a, b;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	a.resize(N); b.resize(M);
	for (ll i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (ll i = 0; i < M; i++) {
		cin >> b[i];
	}

	cout << ans;

	return 0;
}
