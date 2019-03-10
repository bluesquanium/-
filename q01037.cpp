#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, a;
vector<int> nums;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		nums.push_back(a);
	}
	sort(nums.begin(), nums.end());

	cout << nums[0]*nums[nums.size()-1];

	return 0;
}
