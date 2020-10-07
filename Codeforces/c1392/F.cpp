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
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll N, temp;
vector<ll> m, ans;

int main(void) {
	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	m.resize(N);
	ans.resize(N);

	ll sum = 0;
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		sum += m[i];
		ans[i] = i;
	}

	for (ll i = 0; i < N; i++) {
		ans[i] += (sum - (N * (N - 1)) / 2) / N;
	}

	ll rest = (sum - (N * (N - 1)) / 2) % N;
	for (ll i = 0; i < N; i++) {
		if (rest == 0) {
			break;
		}
		ans[i]++;

		rest--;
	}

	for (ll i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}
