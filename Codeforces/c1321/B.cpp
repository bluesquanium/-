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
vector<ll> m;
map<ll, ll> mem;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		if (mem.count(m[i] - i) == 0) {
			mem[m[i] - i] = m[i];
		}
		else {
			mem[m[i] - i] += m[i];
		}
	}

	for (auto iter = mem.begin(); iter != mem.end(); iter++) {
		ans = max(ans, (*iter).second);
	}

	cout << ans;

	return 0;
}
