#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll T, N;
vector<int> arr;
ll aCnt;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	for (ll t = 0; t < T; t++) {
		arr.clear();
		aCnt = 0;
		arr.resize(2);

		cin >> N;

		for (ll i = 2; i <= N && i <= 32000; i++) {
			if (aCnt == 2) {
				break;
			}

			if (N % i == 0) {
				arr[aCnt++] = i;
				N /= i;
			}
		}

		for (int i = 0; i < 2; i++) {
			if (arr[i] >= N) {
				aCnt = 0;
				break;
			}
		}

		if (aCnt == 2) {
			cout << "YES\n";
			for (int i = 0; i < 2; i++) {
				cout << arr[i] << ' ';
			}
			cout << N << '\n';
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
