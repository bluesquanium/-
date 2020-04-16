#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int T, N, K, ans, temp, cnt, uprincess;
vector<int> up; // unmatched prince

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (int i = 0; i < T; i++) {
		ans = 0;
		cnt = 0;
		uprincess = -1;
		cin >> N;
		up.clear();
		up.resize(N + 1, 0);
		for (int j = 1; j <= N; j++) {
			cin >> K;

			int matched = false;
			for (int k = 0; k < K; k++) {
				cin >> temp;

				if (matched == false) {
					if (up[temp] == 0) {
						matched = true;
						up[temp] = 1;
					}
				}
			}
			if (matched == false) {
				uprincess = j;
			}
			else {
				cnt++;
			}
		}

		if (cnt == N) {
			cout << "OPTIMAL\n";
		}
		else {
			cout << "IMPROVE\n";
			for (int j = 1; j <= N; j++) {
				if (up[j] == 0) {
					cout << uprincess << " " << j << '\n';
					break;
				}
			}
		}
	}

	return 0;
}
