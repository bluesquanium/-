#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int wine[n];
	int memo[n];
	for(int i = 0; i < 3 && i < n; i++) {
		cin >> wine[i];
	}
	memo[0] = wine[0];
	memo[1] = wine[0] + wine[1];
	memo[2] = max( max(wine[0]+wine[1], wine[0]+wine[2]), wine[1]+wine[2] );
	for(int i = 3; i < n; i++) {
		cin >> wine[i];
		memo[i] = max( max(memo[i-1], memo[i-2]+wine[i]), memo[i-3] + wine[i-1] + wine[i] );
	}
	
	cout << memo[n-1];
	
	return 0;
}
