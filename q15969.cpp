#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int nums[n];
	for(int i = 0; i < n; i++) cin >> nums[i];
	sort(nums, nums+n);
	
	cout << nums[n-1] - nums[0];
	return 0;
}
