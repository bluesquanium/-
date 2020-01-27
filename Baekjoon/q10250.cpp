#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

#define MAX 99
int T, H, W, N, ans;
int mem[MAX*MAX+1];

void makeMem() {
	int len = MAX * MAX;
	int floor = 0, ho = 0;
	for (int i = 1; i <= len; i++) {
		mem[i] = (floor + 1) * 100 + (ho + 1);

		floor = (floor + 1) % H;
		if (floor == 0) {
			ho = (ho + 1) % W;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> H >> W >> N;
		makeMem();

		cout << mem[N] << '\n';
	}

	return 0;
}
