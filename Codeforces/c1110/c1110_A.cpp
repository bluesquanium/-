#include <iostream>
#include <vector>
using namespace std;

int B, K, M = 1, ans, temp;

int main(void) {
	cin >> B >> K;
	int nums[K];
	for(int i = 0; i < K; i++) {
		cin >> nums[i];
	}
	ans += nums[K-1];
	for(int i = K-2; i >= 0; i--) {
		M = (M*B)%10;
		ans += M*nums[i];
	}
	
	if(ans%2 == 0) {
		cout << "even";
	}
	else {
		cout << "odd";
	}
	
	return 0;
}
