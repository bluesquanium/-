#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define pii	pair<int,int>
using namespace std;

int T, N, M;
long long ans;
vector<int> cycle; // save cycle number for rows.
vector<int> m[12];
map<int, int> index;

void algorithm(int count, int M) {
	if (count < M) {
		for (int i = 0; i < N; i++) {
			cycle[count] = i;
			algorithm(count + 1, M);
		}
	}
	else {
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			int maxi = 0;
			for (int j = 0; j < M; j++) {
				maxi = max(maxi, m[(i + cycle[j]) % N][index[j]]);
			}
			sum += maxi;
		}

		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << m[(i + cycle[j]) % N][j] << ' ';
			}cout << '\n';
		} cout << ans << '\n';
		*/

		ans = max(ans, sum);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	while (T--) {
		ans = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			m[i].clear();
			m[i].resize(M);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> m[i][j];
			}
		}

		if (N <= M) {
			vector<pii> temp;
			for (int j = 0; j < M; j++) {
				int maxi = 0;
				for (int i = 0; i < N; i++) {
					maxi = max(maxi, m[i][j]);
				}
				temp.push_back({ maxi, j });
			}
			sort(temp.rbegin(), temp.rend());

			for (int i = 0; i < N; i++) {
				index[i] = temp[i].second;
			}
			cycle.resize(N, 0);
			algorithm(0, N);
		}
		else {
			for (int i = 0; i < N; i++) {
				index[i] = i;
			}
			cycle.resize(M, 0);
			algorithm(0, M);
		}

		cout << ans << '\n';
	}

	return 0;
}
