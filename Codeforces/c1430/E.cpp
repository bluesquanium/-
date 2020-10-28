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

ll N, M, ans, temp;
string s;
vector<ll> dictIdx[26];

#define MAXBIT 200001
class Bit {
public:
	ll tree[MAXBIT];

	void init() {
		for (ll i = 0; i < MAXBIT; i++) tree[i] = 0;
	}

	void add(ll x, ll v) {
		for (ll i = x; i < MAXBIT; i += i & -i) {
			tree[i] += v;
		}
	}

	ll query(ll x) {
		ll ret = 0;
		for (ll i = x; i; i -= i & -i) {
			ret += tree[i];
		}
		return ret;
	}
} bit;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	cin >> s;

	for (ll i = 0; i < N; i++) {
		dictIdx[s[i] - 'a'].push_back(i);
	}

	for (ll i = 0; i < N; i++) {
		ll target = s[i] - 'a';
		ll targetIdx = dictIdx[target].back(); dictIdx[target].pop_back();
		ll potentialValue = N - 1 - targetIdx;
		ans += potentialValue - bit.query(targetIdx + 1);
		bit.add(1, 1);
		bit.add(targetIdx + 2, -1);
	}

	cout << ans;

	return 0;
}
