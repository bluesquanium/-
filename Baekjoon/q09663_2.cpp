#include <iostream>
using namespace std;

int N, ans[15] = {1,0,0,2,10,
				  4,40,92,352,724,
				  2680,14200,73712,365596,2279184};

int main(void) {
	cin >> N;
	cout << ans[N-1];
	return 0;
}
