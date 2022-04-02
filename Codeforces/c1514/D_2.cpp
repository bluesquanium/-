#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <random>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x0fffffffffffffff // ~= 1e18
#define INF 0x7fffffff
using namespace std;

ll N, Q, ans, temp;
vector<ll> m;
vector<ll> numIdx[300001];

class SegTree {
public:
	const ll DEFAULT_TREE = -INF;
	ll numElement;
	ll segTreeSize;
	vector<ll> tree;
	vector<ll> treeIdxTable;

	void init(vector<ll> &a) {
		numElement = a.size();
		ll height = (ll)ceil(log2(numElement));
		segTreeSize = (1 << (height + 1));
		tree.resize(segTreeSize, DEFAULT_TREE);
		treeIdxTable.resize(numElement);

		initTree(a, 1, 0, numElement - 1);
	}

	ll query(ll left, ll right) {
		return queryTree(1, 0, numElement - 1, left, right);
	}

private:
	ll initTree(vector<ll> &a, ll treeIdx, ll start, ll end) {
		if (start == end) {
			treeIdxTable[start] = treeIdx;
			return tree[treeIdx] = a[start];
		}
		else {
			return tree[treeIdx] = cal(initTree(a, treeIdx * 2, start, (start + end) / 2), initTree(a, treeIdx * 2 + 1, (start + end) / 2 + 1, end), start, end);
		}
	}

	ll queryTree(ll treeIdx, ll start, ll end, ll left, ll right) {
		if (left > end || right < start) {
			return 0;
		}
		if (left <= start && end <= right) {
			return tree[treeIdx];
		}
		return cal(queryTree(treeIdx * 2, start, (start + end) / 2, left, right), queryTree(treeIdx * 2 + 1, (start + end) / 2 + 1, end, left, right), left, right);
	}

	inline ll convertToTreeIdx(ll idx) {
		return treeIdxTable[idx];
	}

	inline ll cal(ll x, ll y, ll left, ll right) {
		ll xNum = upper_bound(numIdx[x].begin(), numIdx[x].end(), right) - lower_bound(numIdx[x].begin(), numIdx[x].end(), left);
		ll yNum = upper_bound(numIdx[y].begin(), numIdx[y].end(), right) - lower_bound(numIdx[y].begin(), numIdx[y].end(), left);

		if (xNum > yNum) {
			return x;
		}
		return y;
	}
} segTree;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> Q;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		numIdx[m[i]].push_back(i);
	}
	segTree.init(m);

	for (ll q = 0; q < Q; q++) {
		ll l, r;
		cin >> l >> r;
		l--; r--;

		ll maxi = segTree.query(l, r);
		ll num = upper_bound(numIdx[maxi].begin(), numIdx[maxi].end(), r) - lower_bound(numIdx[maxi].begin(), numIdx[maxi].end(), l);
		ll numElem = r - l + 1;
		ans = numElem - ((numElem - num) * 2);
		cout << max(1LL, ans) << '\n';
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
