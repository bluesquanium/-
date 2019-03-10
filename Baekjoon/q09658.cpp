#include <iostream>
using namespace std;

int N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;

	if (N % 7 == 1 || N % 7 == 3) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}

	return 0;
}
