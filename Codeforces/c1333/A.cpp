#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
using namespace std;

ll T, N, M, ans;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		
		if ((N * M) % 2 == 1) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if ((i + j) % 2 == 0) {
						cout << 'B';
					}
					else {
						cout << 'W';
					}
				}
				cout << '\n';
			}
		}
		else {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if ((i + j) % 2 == 0 || i * M + j >= N * M - 2) {
						cout << 'B';
					}
					else {
						cout << 'W';
					}
				}
				cout << '\n';
			}
		}
	}

	return 0;
}
