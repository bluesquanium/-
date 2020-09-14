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

#define MAX 100000
ll ftree[MAX + 1][2]; // 0 -

ll N, K, a, b;
char cmd;
vector<ll> m;
string ans;

void fInit(ll N) {
	memset(ftree, 0, sizeof(ll) * 2 * (N + 1));
}

char fCalculate(ll num) {
	ll ret[2] = { 0 };
	while (num > 0) {
		ret[0] += ftree[num][0];
		ret[1] += ftree[num][1];

		num -= num & (-num);
	}

	if (ret[0] > 0) {
		return '0';
	}
	else if (ret[1] % 2 == 0) {
		return '+';
	}
	return '-';
}

char fCalculateRange(ll a, ll b) {
	ll ret[2] = { 0 };
	while (b > 0) {
		ret[0] += ftree[b][0];
		ret[1] += ftree[b][1];

		b -= b & (-b);
	}
	a--;
	while (a > 0) {
		ret[0] -= ftree[a][0];
		ret[1] -= ftree[a][1];

		a -= a & (-a);
	}

	if (ret[0] > 0) {
		return '0';
	}
	else if (ret[1] % 2 == 0) {
		return '+';
	}
	return '-';
}

void fUpdate(ll idx, ll before, ll after) {
	ll delta[2] = { 0 };
	if (before == 0) {
		delta[0]--;
	}
	else if (before < 0) {
		delta[1]--;
	}
	if (after == 0) {
		delta[0]++;
	}
	else if (after < 0) {
		delta[1]++;
	}

	while (idx <= N) {
		ftree[idx][0] += delta[0];
		ftree[idx][1] += delta[1];

		idx += idx & (-idx);
	}
}

int main(void) {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	while (cin >> N >> K) {
		ans.clear();
		fInit(N);
		m.clear(); m.resize(N + 1);
		m[0] = 0;
		for (ll i = 1; i <= N; i++) {
			cin >> m[i];
			fUpdate(i, 1, m[i]);
		}

		for (ll i = 0; i < K; i++) {
			cin >> cmd >> a >> b;
			switch (cmd) {
			case 'C':
				fUpdate(a, m[a], b);
				m[a] = b;
				break;
			case 'P':
				ans.push_back(fCalculateRange(a, b));
				break;
			}
		}
		ans.push_back('\n');
		cout << ans;
	}

	return 0;
}

