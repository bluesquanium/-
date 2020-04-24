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

ll N, K, ans;
vector<ll> m;

bool cmp(ll a, ll b) {
	return a < b;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}

	nth_element(m.begin(), m.begin() + K - 1, m.end(), cmp);

	cout << m[K - 1];

	return 0;
}
