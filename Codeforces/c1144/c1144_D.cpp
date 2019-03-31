#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N, a, eq, eq_i;
vector<int> nums;
vector<tuple<int,int,int>> ans;
unordered_map<int, int> c; // 등장 숫자들 count 위해
unordered_map<int, int>::iterator iter;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		nums.push_back(a);
		c[a] += 1;
	}

	int maxi = 0;
	for (iter = c.begin(); iter != c.end(); iter++) {
		if ((*iter).second > maxi) {
			maxi = (*iter).second;
			eq = (*iter).first;
		}
		//cout << (*iter).first << ' ' << (*iter).second << '\n';
	}

	for (int i = 0; i < N; i++) { // find index of eq
		if (nums[i] == eq) {
			eq_i = i;
			break;
		}
	}

	for (int i = eq_i+1; i < N; i++) {
		if (nums[i] != eq) {
			if (nums[i] < eq) {
				ans.push_back({ 1, i + 1, i });
			}
			else {
				ans.push_back({ 2, i + 1, i });
			}
		}
	}
	for (int i = eq_i - 1; i >= 0; i--) {
		if (nums[i] != eq) {
			if (nums[i] < eq) {
				ans.push_back({ 1, i + 1, i + 2 });
			}
			else {
				ans.push_back({ 2, i + 1, i + 2 });
			}
		}
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << get<0>(ans[i]) << ' ' << get<1>(ans[i]) << ' ' << get<2>(ans[i]) << '\n';
	}

	return 0;
}
