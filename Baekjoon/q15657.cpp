#include <iostream>
#include <vector>
#include <algorithm>
#define ll	long long
using namespace std;

vector<int> nums;
vector<int> v;
int N, M;

void solve(int cur, int c) {
	if (c < M) {
		for (int i = cur; i < N; i++) {
			v[c] = nums[i];
			solve(i, c + 1);
		}
	}
	else {
		for (int i = 0; i < M; i++) {
			cout << v[i] << ' ';
		}cout << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	v.resize(M); nums.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());

	solve(0, 0);

	return 0;
}
