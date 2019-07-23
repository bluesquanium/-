#include <iostream>
#define ll	long long
using namespace std;

ll n;

int main(void) {
	cin >> n;
	n = (n + 5 - 4) % 5;
	if ( n == 0 || n == 2 || n == 4 ) cout << "SK";
	else cout << "CY";

	return 0;
}

