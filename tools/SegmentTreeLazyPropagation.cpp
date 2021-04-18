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

class LazySegTree {
public:
	const ll DEFAULT_TREE = -INF;
	const ll DEFAULT_LAZY = 0;
	ll numElement;
	ll segTreeSize;
	vector<ll> tree;
	vector<ll> lazy;

	void init(vector<ll> &a) {
		numElement = a.size();
		ll height = (ll)ceil(log2(numElement));
		segTreeSize = (1 << (height + 1));
		tree.resize(segTreeSize, DEFAULT_TREE);
		lazy.resize(segTreeSize, DEFAULT_LAZY);

		initTree(a, 1, 0, numElement - 1);
	}

	ll query(ll left, ll right) {
		return queryTree(1, 0, numElement - 1, left, right);
	}

	void updateRange(ll left, ll right, ll diff) {
		updateRangeTree(1, 0, numElement - 1, left, right, diff);
	}

private:
	void updateRangeTree(ll treeIdx, ll start, ll end, ll left, ll right, ll diff) {
		updateLazy(treeIdx, start, end);
		if (left > end || right < start) {
			return;
		}
		if (left <= start && end <= right) {
			tree[treeIdx] += (end - start + 1)*diff;
			if (start != end) {
				lazy[treeIdx * 2] += diff;
				lazy[treeIdx * 2 + 1] += diff;
			}
			return;
		}
		updateRangeTree(treeIdx * 2, start, (start + end) / 2, left, right, diff);
		updateRangeTree(treeIdx * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
		tree[treeIdx] = cal(tree[treeIdx * 2], tree[treeIdx * 2 + 1]);
	}

	void updateLazy(ll treeIdx, ll start, ll end) {
		if (lazy[treeIdx] != DEFAULT_LAZY) {
			tree[treeIdx] += (end - start + 1)*lazy[treeIdx];
			// leaf가 아니면
			if (start != end) {
				if (tree[treeIdx * 2] != DEFAULT_TREE) {
					lazy[treeIdx * 2] += lazy[treeIdx];
				}
				if (tree[treeIdx * 2 + 1] != DEFAULT_TREE) {
					lazy[treeIdx * 2 + 1] += lazy[treeIdx];
				}
			}
			lazy[treeIdx] = DEFAULT_LAZY;
		}
	}

	ll initTree(vector<ll> &a, ll treeIdx, ll start, ll end) {
		if (start == end) {
			return tree[treeIdx] = a[start];
		}
		else {
			return tree[treeIdx] = cal(initTree(a, treeIdx * 2, start, (start + end) / 2), initTree(a, treeIdx * 2 + 1, (start + end) / 2 + 1, end));
		}
	}

	ll queryTree(ll treeIdx, ll start, ll end, ll left, ll right) {
		updateLazy(treeIdx, start, end);
		if (left > end || right < start) {
			return 0;
		}
		if (left <= start && end <= right) {
			return tree[treeIdx];
		}
		return cal(queryTree(treeIdx * 2, start, (start + end) / 2, left, right), queryTree(treeIdx * 2 + 1, (start + end) / 2 + 1, end, left, right));
	}

	inline ll cal(ll x, ll y) {
		return x + y;
	}
} lazySegTree;

ll N, M, K, ans, temp;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> K;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}

	lazySegTree.init(m);

	for (ll q = 0; q < M + K; q++) {
		ll a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			b--; c--;
			lazySegTree.updateRange(b, c, d);
		}
		else {
			cin >> b >> c;
			b--; c--;
			cout << lazySegTree.query(b, c) << '\n';
		}
	}

	return 0;
}
