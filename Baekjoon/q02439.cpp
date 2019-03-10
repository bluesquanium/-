#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for(int i = 1; i <= n ; i++) cout << setw(n) << string(i,'*') << '\n';
	return 0;
}
