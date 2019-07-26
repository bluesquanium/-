#include <iostream>
using namespace std;

int T;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;
		cout << 1+(n-m)*m << '\n';
	}

	return 0;
}
