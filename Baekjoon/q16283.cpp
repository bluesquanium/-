#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll A, B, N, W, big, small;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> A >> B >> N >> W;
	if (N == 2 && A + B == W) {
		cout << "1 1";
	}
	else if (A == B) {
		cout << "-1";
	}
	else {
		if (A > B) {
			big = A;
			small = B;
		}
		else {
			big = B;
			small = A;
		}

		ll sum = small * N;
		if (sum > W) {
			cout << "-1";
		}
		else {
			if ((W - sum) % (big - small)) {
				cout << "-1";
			}
			else {
				big = (W - sum) / (big - small);
				small = N - big;
				if (big == 0 || small == 0) {
					cout << "-1";
				}
				else if (A > B) {
					cout << big << ' ' << small;
				}
				else {
					cout << small << ' ' << big;
				}
			}
		}

	}

	return 0;
}
