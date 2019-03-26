#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
long long ans;
long long nums[300001];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL), cin.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	sort(nums, nums + N);
	for (int i = 1; i < N; i++) {
		if (i <= K) {
			ans += nums[i] * i;
		}
		else {
			ans += nums[i] * K;
		}
		
	}

	cout << ans;
	return 0;
}
