#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll A, ans;
vector<int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	m.resize(42);	
	for (int i = 0; i < 10; i++) {
		cin >> A;
		m[A % 42] = 1;
	}
	for (int i = 0; i < 42; i++) {
		ans += m[i];
	}

	cout << ans << '\n';

	return 0;
}
