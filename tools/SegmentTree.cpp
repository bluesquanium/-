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
			return tree[treeIdx] = a[start];
		}
		else {
			return tree[treeIdx] = cal(initTree(a, treeIdx * 2, start, (start + end) / 2), initTree(a, treeIdx * 2 + 1, (start + end) / 2 + 1, end));
		}
	}

	ll queryTree(ll treeIdx, ll start, ll end, ll left, ll right) {
		if (left > end || right < start) {
			return 0;
		}
		if (left <= start && end <= right) {
			return tree[treeIdx];
		}
		return cal(queryTree(treeIdx * 2, start, (start + end) / 2, left, right), queryTree(treeIdx * 2 + 1, (start + end) / 2 + 1, end, left, right));
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

		if (treeIdx * 2 >= segTreeSize || (treeIdx * 2 < segTreeSize && tree[treeIdx * 2] == DEFAULT_TREE)) {
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

ll N, M, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	m.resize(N, 0);

	segTree.init(m);

	for (ll q = 0; q < M; q++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			b--; c--;
			if (b > c) {
				swap(b, c);
			}
			cout << segTree.query(b, c) << '\n';
		}
		else {
			b--;
			if (true) segTree.update(b, c - m[b]);
			else segTree.updateFromBottom(b, c - m[b]);
			m[b] = c;
		}
	}

	return 0;
}
