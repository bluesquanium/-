#include <iostream>
#define ll	long long
using namespace std;

#define MAX 32000
ll N, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N;
	for(int i = 0; i < 32000; i++) {
		if( N <=1 + 3*i * i + 3 * i) {
			ans = i + 1;
			break;
		}
	}

	cout << ans;

	return 0;
}
