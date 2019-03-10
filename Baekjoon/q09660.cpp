#include <iostream>
using namespace std;

long long N;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;

	if (N % 7 == 2 || N % 7 == 0) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}

	return 0;
}
