#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, a, ans;
vector<int> nums, asc, dsc;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		nums.push_back(a);
	}
	sort(nums.begin(), nums.end());

	asc.push_back(nums[nums.size() - 1]);
	int prev = nums[nums.size() - 1], pprev = -1;
	bool c = true;
	nums.pop_back();
	for (int i = nums.size()-1; i >= 0; i--) {
		if (prev == nums.back() && prev == pprev) {
			c = false;
		}

		if (nums.back() == prev) {
			dsc.push_back(nums[i]);
		}
		else {
			asc.push_back(nums[i]);
		}
		pprev = prev;
		prev = nums.back();
		nums.pop_back();
	}

	if (c == false) {
		cout << "NO";
	}
	else {
		cout << "YES\n";
		cout << asc.size() << '\n';
		for (int i = asc.size() - 1; i >= 0; i--) {
			cout << asc[i] << ' ';
		}cout << '\n';
		cout << dsc.size() << '\n';;
		for (int i = 0; i < dsc.size(); i++) {
			cout << dsc[i] << ' ';
		}cout << '\n';
	}

	return 0;
}
