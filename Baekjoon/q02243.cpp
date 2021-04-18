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

class SegTree {
public:
	ll DEFAULT = -INF;
	ll numElement;
	ll segTreeSize;
	vector<ll> tree;
	vector<ll> treeIdxTable;
	vector<ll> realIdxTable;

	void init(vector<ll> &a) {
		numElement = a.size();
		ll height = (ll)ceil(log2(numElement));
		segTreeSize = (1 << (height + 1));
		tree.resize(segTreeSize, DEFAULT);
		realIdxTable.resize(segTreeSize);
		treeIdxTable.resize(numElement);

		initTree(a, 1, 0, numElement - 1);
	}

	ll query(ll rank) {
		ll ret = queryTree(1, 0, numElement - 1, rank, 0);
		update(ret, -1);
		return ret;
	}

	void update(ll index, ll diff) {
		updateTree(1, 0, numElement - 1, index, diff);
	}

	void updateFromBottom(ll index, ll diff) {
		updateTreeFromBottom(convertToTreeIdx(index), diff);
	}

private:
	ll initTree(vector<ll> &a, ll treeIdx, ll start, ll end) {
		if (start == end) {
			treeIdxTable[start] = treeIdx;
			realIdxTable[treeIdx] = start;
			return tree[treeIdx] = a[start];
		}
		else {
			return tree[treeIdx] = cal(initTree(a, treeIdx * 2, start, (start + end) / 2), initTree(a, treeIdx * 2 + 1, (start + end) / 2 + 1, end));
		}
	}

	ll queryTree(ll treeIdx, ll start, ll end, ll targetRank, ll rankSum) {
		if (treeIdx * 2 >= segTreeSize || tree[treeIdx * 2] == DEFAULT) {
			return realIdxTable[treeIdx];
		}
		else if (treeIdx * 2 + 1 >= segTreeSize || tree[treeIdx * 2 + 1] == DEFAULT) {
			return queryTree(treeIdx * 2, start, (start + end) / 2, targetRank, rankSum);
		}
		else if (targetRank <= rankSum + tree[treeIdx * 2]) {
			return queryTree(treeIdx * 2, start, (start + end) / 2, targetRank, rankSum);
		}
		return queryTree(treeIdx * 2 + 1, (start + end) / 2 + 1, end, targetRank, rankSum + tree[treeIdx * 2]);
	}

	void updateTree(ll treeIdx, ll start, ll end, ll index, ll diff) {
		if (index < start || index > end) return;
		tree[treeIdx] = updateCal(tree[treeIdx], diff);
		if (start != end) {
			updateTree(treeIdx * 2, start, (start + end) / 2, index, diff);
			updateTree(treeIdx * 2 + 1, (start + end) / 2 + 1, end, index, diff);
		}
	}

	void updateTreeFromBottom(ll treeIdx, ll diff) {
		if (treeIdx == 0) {
			return;
		}

		if (treeIdx * 2 >= segTreeSize || (treeIdx * 2 < segTreeSize && tree[treeIdx * 2] == DEFAULT)) {
			tree[treeIdx] = updateCal(tree[treeIdx], diff);
		}
		else {
			if (treeIdx * 2 + 1 < segTreeSize) {
				tree[treeIdx] = cal(tree[treeIdx * 2], tree[treeIdx * 2 + 1]);
			}
			else {
				tree[treeIdx] = tree[treeIdx * 2];
			}
		}

		updateTreeFromBottom(treeIdx / 2, diff);
	}

	inline ll convertToTreeIdx(ll idx) {
		return treeIdxTable[idx];
	}

	inline ll cal(ll x, ll y) {
		return x + y;
	}

	inline ll updateCal(ll treeVal, ll diff) {
		return treeVal + diff;
	}
} segTree;

ll Q, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> Q;
	m.resize(1000000, 0);

	segTree.init(m);

	for (ll q = 0; q < Q; q++) {
		ll a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b;
			cout << segTree.query(b) + 1 << '\n';
		}
		else {
			cin >> b >> c;
			b--;
			segTree.update(b, c);
		}
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
