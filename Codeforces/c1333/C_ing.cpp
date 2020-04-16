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
using namespace std;

#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff

ll N, M, ans;
vector<ll> m, block;
map< ll, vector<ll> > blockFind;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N); block.resize(N, LINF);

	ans = N * (N + 1) / (ll) 2;
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}

	ll sum = 0;
	for (ll i = 0; i < N; i++) {
		sum += m[i];
		if (blockFind.count(sum) == 0) {
			vector<ll> temp;
			blockFind[sum] = temp;
			temp.clear();
		}
		blockFind[sum].push_back(i);
	}
	for (auto iter = blockFind.begin(); iter != blockFind.end(); iter++) {
		sort((*iter).second.rbegin(), (*iter).second.rend());
	}
	sum = 0;
	for (ll i = 0; i < N; i++) {
		if (blockFind.count(sum)) {
			while (!blockFind[sum].empty()) {
				if (blockFind[sum].back() < i) {
					blockFind[sum].pop_back();
				}
				else {
					block[i] = blockFind[sum].back();

					break;
				}
			}
		}
		sum += m[i];
	}

	ll prev = -1;
	for (ll i = 0; i < N; i++) {
		if (block[i] != LINF) {
			ans -= (ll)((ll)N - (ll)block[i]) * (ll)( (ll)i - (ll)prev );

			prev = i;
		}
	}

	cout << ans;

	return 0;
}
