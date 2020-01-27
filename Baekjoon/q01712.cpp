#include <iostream>
#define ll	long long
using namespace std;

ll A, B, C, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> A >> B >> C;
	if(C- B <= 0) {
		cout << -1;
	} else {
		ans = A / (C - B) + 1;
	
		cout << ans;
	}


	return 0;
}
