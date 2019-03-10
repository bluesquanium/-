#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	int n, k;
	double result = 1.7e+308;
	cin >> n >> k;
	int dolls[n];
	for(int i = 0; i < n; i++) {
		cin >> dolls[i];
	}
	
	for(int i = k; i <= n; i++) {
		for(int j = 0; j <= n-i; j++) {
			int sum = 0;
			double avg, var = 0;
			for(int l = j; l < j+i; l++) {
				sum += dolls[l];
			}
			avg = (double)sum / (double)i;
			for(int l = j; l < j+i; l++) {
				var += ((double)dolls[l] - avg) * ((double)dolls[l] - avg);
			}
			var = var / (double)i;
			result = min(result, var);
		}
	}
	
	result = sqrt(result);
	cout.precision(10);
	cout << result;
	
	return 0;
}
