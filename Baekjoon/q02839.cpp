#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Solve(int num) {
	if(num<3 || num==4) return 10000;
	else if(num==3 || num==5) return 1;
	
	int res1 = Solve(num-3) + 1;
	int res2 = Solve(num-5) + 1;
	return res1<res2?res1:res2;
}

int main(void) {
	int n;
	cin >> n;
	
	int result = Solve(n);
	if(result >= 10000) {
		cout << -1;
	}
	else {
		cout << Solve(n);
	}
	return 0;
}
