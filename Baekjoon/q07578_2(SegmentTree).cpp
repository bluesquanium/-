#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#define DTYPE	long long
using namespace std;


int N, temp;
DTYPE ans;
vector<DTYPE> a;
unordered_map<DTYPE, int> r; // r : range

class Seg {
private:
	vector<DTYPE> tree;
	int tSize;
public:
	Seg(int n) {
		int h = (int)ceil(log2(n));
		tSize = (1 << (h + 1));
		tree.resize(tSize);
	}

	void getTSize() {
		cout << tSize << '\n';
	}

	DTYPE init(vector<DTYPE> &a, int cur, int start, int end) {
		if (start == end) {
			return tree[cur] = a[start];
		}
		else {
			return tree[cur] = init(a, cur * 2, start, (start + end) / 2)
				+ init(a, cur * 2 + 1, (start + end) / 2 + 1, end);
		}
	}

	DTYPE sum(int cur, int start, int end, int left, int right) {
		if (left > end || right < start) {
			return 0;
		}
		else if (left <= start && end <= right) {
			return tree[cur];
		}
		else {
			return sum(cur * 2, start, (start + end) / 2, left, right) + sum(cur * 2 + 1, (start + end) / 2 + 1, end, left, right);
		}
	}

	void update(int cur, int start, int end, int index, int diff) {
		if (index < start || index > end) return;
		tree[cur] = tree[cur] + diff;
		if (start != end) {
			update(cur * 2, start, (start + end) / 2, index, diff);
			update(cur * 2 + 1, (start + end) / 2 + 1, end, index, diff);
		}
	}

	void printAll() {
		for (int i = 0; i < tSize; i++) {
			cout << tree[i] << ' ';
		}cout << '\n';
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	a.resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		r[temp] = i;
	}
	Seg seg = Seg(N);
	seg.init(a, 1, 0, N - 1);
	for (int i = 0; i < N; i++) {
		cin >> temp;

		ans += seg.sum(1, 0, N - 1, r[temp], N - 1);
		seg.update(1, 0, N - 1, r[temp], 1);
	}

	cout << ans;

	return 0;
}
