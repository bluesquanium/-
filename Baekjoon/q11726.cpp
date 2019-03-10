#include <iostream>
using namespace std;

int main(void) {
	long long int n;
	cin >> n;
	int mem[n+1];
	
	mem[1] = 1; mem[2] = 2; mem[3] = 3;
	for(int i = 4; i <= n; i++) {
		mem[i] = (mem[i-1] + mem[i-2])%10007;
	}
	
	/*
	for(int i = 0; i*2 <= n; i++) {
		if(i*2 == n || i == 0) {
			num += 1;
		}
		else {
			long long temp = 1;
			for(int j = n-2*i+1; j <= n-i; j++) {
				temp *= j;
			}
			for(int j = 1; j <= i; j++) {
				temp /= j;
			}
			num += temp;
		}
	}
	*/
	cout << mem[n];
	
	return 0;
}
