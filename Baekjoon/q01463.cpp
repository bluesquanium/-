#include <iostream>
#include <algorithm>
using namespace std;

int Calculate(int num) {
	if(num<=1) return 0;
	return min( (1 + num%3 + Calculate(num/3)), (1 + num%2 + Calculate(num/2)) );
}

int main(void) {
	int n, count = 0;
	cin >> n;
	
	cout << Calculate(n);
}
