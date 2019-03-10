#include <iostream>
#include <cstring>
using namespace std;

#define abs(X)	(X)>0?(X):-(X)
#define min(X,Y)	(X)>(Y)?(Y):(X)
long long gcd(long long x, long long y) {
	return y?gcd(y,x%y):x;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long a, b, num1, num2;
	cin >> a >> b;
	num1 = abs(a-b);
	num2 = min(a,b);
	cout << string( gcd(num1, num2) , '1');
	
	return 0;
}
