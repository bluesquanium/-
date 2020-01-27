#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, ans;
pii mem[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;

	mem[2] = mem[3] = { 1, 1 };
	for (int i = 4; i <= N; i++) {
		mem[i] = {mem[i-1].first + 1, i-1};
		if (i % 2 == 0 && mem[i].first-1 > mem[i/2].first) {
			mem[i] = { mem[i / 2].first + 1, i / 2 };
		}
		if (i % 3 == 0 && mem[i].first-1 > mem[i/3].first) {
			mem[i] = { mem[i / 3].first + 1, i / 3 };
		}
	}

	int cur = N;
	printf("%d\n", mem[cur].first);
	while (cur != 1) {
		printf("%d ", cur);
		cur = mem[cur].second;
	}
	printf("%d", cur);

	return 0;
}
