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

ll N, M, K, temp;
ll ans;
pll ansRange;
string a, b;
vector<pll> elves;

#define MAXK 20
#define MAXMEM 1048576

ll p[MAXK];
ll pIndex[MAXK];

ll memA[MAXMEM];
ll memB[MAXMEM];

ll Count1(ll num) {
	ll ret = 0;
	while (num) {
		if (num % 2) {
			ret++;
		}
		num /= 2;
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> K;
	cin >> a;
	cin >> b;

	ll a1cnt = count(a.begin(), a.end(), '1'), b1cnt = count(b.begin(), b.end(), '1');
	for (ll i = 0; i < K; i++) {
		p[i] = i;
		pIndex[i] = i;
	}

	for (ll i = 0; i < (1 << K); i++) {
		memA[i] = INF;
		memB[i] = -INF;
	}

	ll cura = 0, curb = 0;
	for (ll i = 0; i < K; i++) {
		cura *= 2;
		cura += a[p[i]] - '0';

		curb *= 2;
		curb += b[p[i]] - '0';
	}

	memA[cura] = 0;
	memB[curb] = 0;

	elves.resize(N + 1);
	for (ll i = 1; i <= N; i++) {
		cin >> elves[i].first >> elves[i].second;
		elves[i].first--; elves[i].second--;
		swap(p[pIndex[elves[i].first]], p[pIndex[elves[i].second]]);
		swap(pIndex[elves[i].first], pIndex[elves[i].second]);

		ll cura = 0, curb = 0;
		for (ll j = 0; j < K; j++) {
			cura *= 2;
			cura += a[p[j]] - '0';

			curb *= 2;
			curb += b[p[j]] - '0';
		}

		memA[cura] = min(memA[cura], i);
		memB[curb] = i;
	}

	ans = 0;
	ansRange = { 1, M };
	for (ll i = (1 << K) - 1; i >= 0; i--) {
		if (memB[i] - memA[i] >= M) {
			// w = k - a1cnt - b1cnt + 2 * same1	
			ll cnt1 = K - a1cnt - b1cnt + 2 * Count1(i);
			if (ans < cnt1) {
				ans = cnt1;
				ansRange.first = memA[i] + 1;
				ansRange.second = memB[i];
			}
		}

		for (ll j = 0; j < K; j++) {
			if (i & (1 << j)) {
				memA[i ^ (1 << j)] = min(memA[i ^ (1 << j)], memA[i]);
				memB[i ^ (1 << j)] = max(memB[i ^ (1 << j)], memB[i]);
			}
		}
	}

	cout << ans << '\n';
	cout << ansRange.first << ' ' << ansRange.second;

	return 0;
}
