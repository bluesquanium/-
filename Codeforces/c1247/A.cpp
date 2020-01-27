#include <iostream>
using namespace std;

int d[2], ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> d[0] >> d[1];
	if (d[0] == d[1]) {
		if (d[0] != 0) {
			cout << d[0];
		}
		cout << 0 << ' ';
		if (d[1] != 0) {
			cout << d[1];
		}
		cout << 1;
	}
	else if (d[0] + 1 == d[1]) {
		if (d[0] != 0) {
			cout << d[0];
		}
		cout << 9 << ' ';
		if (d[1] != 0) {
			cout << d[1];
		} 
		cout << 0;
	}
	else if (d[0] == 9 && d[1] == 1) {
			cout << 9 << ' ' << 10;
		}
	else {
		cout << -1;
	}

	return 0;
}
