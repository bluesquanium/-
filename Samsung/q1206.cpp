#include <iostream>
using namespace std;

int main(void) {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	
	int t = 10, n;
	for(int l = 1; l <= t; l++) {
		int left, right, a, result = 0;
		cin >> n;
		int building[n];
		for(int i = 0; i < n; i++) cin >> building[i];
		left = 0; right = 0;
		for(int i = 2; i < n-2; i++) {
			left = max(building[i-2], building[i-1]);
			right = max(building[i+1], building[i+2]);
			a = building[i] - max(left, right);
			if(a > 0) result += a;
		}
		
		cout << '#' << l << ' ' << result << '\n';
	}
	
	return 0;
}
