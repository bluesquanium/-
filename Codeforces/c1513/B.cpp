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
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

#define MOD 1000000007

ll T, N, M, ans, temp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		map<ll, ll> numCntMap;
		map<ll, vector<ll> > numBitMap;
		ll bitCnt[31] = { 0 };

		ans = 0;
		cin >> N;
		for (ll i = 0; i < N; i++) {
			cin >> temp;
			if (numCntMap.count(temp) == 0) {
				numCntMap[temp] = 1;
			}
			else {
				numCntMap[temp]++;
			}

			vector<ll> v;
			ll num = temp, j = 0;
			while (num) {
				if (num % 2 != 0) {
					v.push_back(j);
					bitCnt[j]++;
				}
				num /= 2;
				j++;
			}
			numBitMap[temp] = v;
		}

		for (auto iter = numCntMap.begin(); iter != numCntMap.end(); iter++) {
			ll num = (*iter).first;
			ll cnt = (*iter).second;
			if (cnt >= 2) {
				if (num != 0) {
					int check = 1;
					for (ll i = 0; i < numBitMap[num].size(); i++) {
						ll targetBit = numBitMap[num][i];
						if (bitCnt[targetBit] != N) {
							check = 0;
							break;
						}
					}
					if (check == 0) {
						continue;
					}
				}
				
				ll mul = 1;
				mul *= cnt * (cnt - 1);
				mul %= MOD;
				for (ll i = 2; i <= N - 2; i++) {
					mul *= i;
					mul %= MOD;
				}

				ans += mul;
				ans %= MOD;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}

/*
0. Enough array size? Enough array size? Integer overflow?

1. Think TWICE, Code ONCE!
Are there any counterexamples to your algo?

2. Be careful about the BOUNDARIES!
N=1? P=1? Something about 0?

3. Do not make STUPID MISTAKES!
Time complexity? Memory usage? Precision error?

4. Be careful to wrong variable.
*/
