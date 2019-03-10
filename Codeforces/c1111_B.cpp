#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cout << fixed;
    cout.precision(20);

	int n, k, m, temp, maxi = 0;
	long long sum = 0;
	double result = 0;
	cin >> n >> k >> m;
	int heroes[n];
	for(int i = 0; i < n; i++) {
		cin >> heroes[i];
		sum += heroes[i];
	}
	sort(heroes, heroes+n);
	
	for(int i = 0; i < n; i++) {
		if(i<=m) {
			long long g = min((long long)k*(n-i), (long long)m-i);
			result = max(result, (double)(sum+g)/(n-i));
			sum -= heroes[i];
		}
	}
	
	cout << result;

	return 0;
}
