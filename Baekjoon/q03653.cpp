#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#define DTYPE	int
using namespace std;

class Seg{
private :
	vector<DTYPE> tree;
	int tSize;
public :
	Seg(int n) {
		int h = (int)ceil(log2(n));
		tSize = (1 << (h + 1));
		tree.resize(tSize);
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

	// 특정 값 val로 초기화 하고 싶을 때
	DTYPE init(DTYPE val, int cur, int start, int end) {
		if (start == end) {
			return tree[cur] = val;
		}
		else {
			return tree[cur] = init(val, cur * 2, start, (start + end) / 2)
				+ init(val, cur * 2 + 1, (start + end) / 2 + 1, end);
		}
	}

	DTYPE sum(int cur, int start, int end, int left, int right) {
		if (right < start || end < left) {
			return 0;
		}
		else if (left <= start && end <= right) {
			return tree[cur];
		}
		else {
			return sum(cur * 2, start, (start + end) / 2, left, right)
				 + sum(cur * 2 + 1, (start + end) / 2 + 1, end, left, right);
		}
	}

	void update(int cur, int start, int end, int target_index, int diff) {
		if (target_index < start || target_index > end) return;
		tree[cur] += diff;
		if (start != end) {
			update(cur * 2, start, (start + end) / 2, target_index, diff);
			update(cur * 2 + 1, (start + end) / 2 + 1, end, target_index, diff);
		}
	}

	void printAll() {
		int step = 1, until = 2;

		for (int i = 1; i < tSize; i++) {
			if (i >= until) {
				step *= 2;
				until += step;
				cout << '\n';
			}
			cout << tree[i] << ' ';
		}cout << '\n';
	}
};

int T, N, M, ans, temp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> M;

		unordered_map<DTYPE, int> r;
		Seg seg(N + M); // 일반 크기 N + dvd를 맨 위에 올리면서 늘어나는 크기 M
		seg.init(0, 1, 0, N + M - 1);
		for (int i = 0; i < N; i++) {
			seg.update(1, 0, N + M - 1, i, 1);
			r[N-i] = i;
		}

		for (int i = 1; i <= M; i++) {
			cin >> temp;
			cout << seg.sum(1, 0, N + M - 1, r[temp] + 1, N + M - 1) << ' ';

			seg.update(1, 0, N + M - 1, r[temp], -1);
			seg.update(1, 0, N + M - 1, N + i - 1, 1);
			r[temp] = N + i - 1;

			/*
			cout << '\n';
			seg.printAll();
			cout << '\n';
			*/
		}
		cout << '\n';
	} 

	return 0;
}
