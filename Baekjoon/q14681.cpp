#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int X, Y, ans;
vector<int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> X >> Y;
	if (X > 0) {
		if (Y > 0) {
			cout << 1;
		}
		else {
			cout << 4;
		}
	}
	else {
		if (Y > 0) {
			cout << 2;
		}
		else {
			cout << 3;
		}
	}

	return 0;
}
