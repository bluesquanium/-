#include <iostream>
using namespace std;

int m, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	for (int i = 0; i < 3; i++) {
		ans = 1;
		for (int j = 0; j < 4; j++) {
			cin >> m;
			ans += m;
		}
		cout << char('E' - ans % 5) << '\n';
	}

	return 0;
}
