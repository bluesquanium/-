#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll A, B, V, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> A >> B >> V;
	
	ans = (V - B) / (A - B);
	if ((V - B) % (A - B)) {
		ans++;
	}
	cout << ans;

	return 0;
}
