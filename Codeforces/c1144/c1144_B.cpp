#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, a, ans;
vector<int> odd, even;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a % 2 == 0) {
			even.push_back(a);
		}
		else {
			odd.push_back(a);
		}
	}
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());

	int d = 0;
	if (odd.size() > even.size()) {
		d = odd.size() - even.size();
		for (int i = 0; i < d-1; i++) {
			ans += odd[i];
		}
	}
	else if (odd.size() < even.size()) {
		d = even.size() - odd.size();
		for (int i = 0; i < d - 1; i++) {
			ans += even[i];
		}
	}

	cout << ans;
	return 0;
}
