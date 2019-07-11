#include <iostream>
using namespace std;

int S1, S2, t1, t2;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> S1 >> S2;
	for (int i = 0; i < S1; i++) {
		cin >> t1 >> t2;
		if (t1 != t2) {
			cout << "Wrong Answer";
			return 0;
		}
	}
	for (int i = 0; i < S2; i++) {
		cin >> t1 >> t2;
		if (t1 != t2) {
			cout << "Why Wrong!!!";
			return 0;
		}
	}

	cout << "Accepted";

	return 0;
}
