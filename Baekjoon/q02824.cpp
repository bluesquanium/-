#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int x, int y) {
	return y?gcd(y, x&y):x;
}

int main(void) {
	int n, m, result = 2147483647;
	cin >> n;
	int num1[n];
	for(int i = 0; i < n; i++) {
		cin >> num1[i];
	}
	cin >> m;
	int num2[m];
	for(int i = 0; i < m; i++) {
		cin >> num2[m];
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int temp = gcd(num1[i], num2[j]);
			num1[i] = min(num1[i], temp);
		}
		//result = min(result, num1[i]);
	}
	
	cout << result;
	return 0;
}
