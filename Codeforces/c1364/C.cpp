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

ll N, M;
ll visited[1000001];
ll m[100001], ans[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;

	vector<ll> empty;
	ll ecnt = 0;
	for (ll i = 0; i < 100001; i++) {
		ans[i] = -1;
	}

	cin >> m[0];
	for (ll i = 1; i < N; i++) {
		cin >> m[i];
		if (m[i] != m[i - 1]) {
			ans[i] = m[i - 1];
			visited[m[i - 1]] = 1;
		}
	}

	for (ll i = 0; i < m[N - 1]; i++) {
		if (visited[i] == 0) {
			empty.push_back(i);
		}
	}

	for (ll i = 0; i < N; i++) {
		if (ans[i] != -1) {
			cout << ans[i] << ' ';
		}
		else {
			ll num;
			if (empty.size() == 0) {
				num = m[N - 1] + 1;
			}
			else if (ecnt < empty.size()) {
				num = empty[ecnt];
				ecnt++;
			}
			else {
				num = empty.back();
			}
			cout << num << ' ';
		}
	}

	return 0;
}
