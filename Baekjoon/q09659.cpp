#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string s;
	cin >> s;
	
	if ((s[s.length() - 1] - '0') % 2 == 0 ) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}

	return 0;
}
