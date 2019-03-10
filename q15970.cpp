#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> nums[5001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, color, max_color = 0, sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x >> color;
		nums[color].push_back(x);
		max_color = max(max_color, color);
	}
	for(int i = 1; i <= max_color; i++) sort(nums[i].begin(), nums[i].end());
	
	for(int i = 1; i <= max_color; i++) {
		for(int j = 0; j < nums[i].size(); j++) {
			if( j == 0 ) sum += (nums[i])[j+1] - (nums[i])[j];
			else if( j == nums[i].size()-1 ) sum += (nums[i])[j] - (nums[i])[j-1];
			else sum += min( (nums[i])[j]-(nums[i])[j-1], (nums[i])[j+1]-(nums[i])[j] );
		}
	}
	
	cout << sum;

	return 0;
}
