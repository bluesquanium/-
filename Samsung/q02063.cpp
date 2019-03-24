#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans;
int nums[200];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	sort(nums, nums + N);

	cout << nums[N / 2];

	return 0;
}
