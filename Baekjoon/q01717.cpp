#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, M, ans, t, a, b;
vector<int> parent;

int Find(int x) {
	// Root인 경우 x를 반환
	if (x == parent[x]) {
		return x;
	}
	else {
		// 아니면 Root를 찾아감
		int p = Find(parent[x]);
		parent[x] = p;
		return p;
	}
}
void Union(int x, int y) {

	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	parent.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> t >> a >> b;
		if (t) {
			if (Find(a) == Find(b)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
		else {
			Union(a, b);
		}
	}

	return 0;
}
