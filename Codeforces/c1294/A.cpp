#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int T, A, B, C, N, ans, maxi;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++) {
		ans = maxi = 0;
		cin >> A >> B >> C >> N;
		maxi = A > maxi ? A : maxi;
		maxi = B > maxi ? B : maxi;
		maxi = C > maxi ? C : maxi;
		int num = 0;
		num += maxi * 3 - (A + B + C);
		N -= num;

		if (N >= 0 && N % 3 == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
