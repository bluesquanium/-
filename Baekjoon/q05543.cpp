#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, ham, bav;
vector<int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	ham = 99999;
	bav = 99999;
	for (int i = 0; i < 3; i++) {
		cin >> N;

		if (ham > N) {
			ham = N;
		}
	}
	for (int i = 0; i < 2; i++) {
		cin >> N;

		if (bav > N) {
			bav = N;
		}
	}

	cout << ham + bav - 50;

	return 0;
}
