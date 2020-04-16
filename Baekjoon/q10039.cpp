#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, ans;
vector<int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	for (int i = 0; i < 5; i++) {
		cin >> N;
		if (N < 40) {
			ans += 40;
		}
		else {
			ans += N;
		}
	}

	cout << ans / 5;

	return 0;
}
