#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, a;
int m[500][2][10];
int ans[2][10];
int ret;
vector<int> visited[2][10];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	memset(m, -1, sizeof(int) * 500 * 2 * 10);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a;
			for (int k = 0; k < 10; k++) {
				if ( (a & 1) == 0) {
					m[i][0][k] = j;
				}
				else {
					m[i][1][k] = j;
				}
				a /= 2;
			}
		}
	}

	/*
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 10; k++) {
				cout << m[i][j][k] << ' ';
			}cout << endl;
		}
	}cout << endl;
	*/

	for (int i = 0; i < 2; i++) { // N = 0¹øÂ°
		for (int j = 0; j < 10; j++) {
			ans[i][j] = (m[0][i][j] == -1 ? 0 : 1);
			if (m[0][i][j] != -1) {
				visited[i][j].push_back(m[0][i][j]);
			}
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			vector<int> temp0, temp1;
			//0
			if ((ans[0][j] == 1 && (m[i][0][j] == -1 ? 0 : 1) == 1)) {
				ans[0][j] = 1;
				temp0 = visited[0][j];
				temp0.push_back(m[i][0][j]);
			}
			else if ( (ans[1][j]==1 && (m[i][1][j] == -1 ? 0 : 1)==1) ) {
				ans[1][j] = 1;
				temp0 = visited[1][j];
				temp0.push_back(m[i][1][j]);
			}
			//1
			if ((ans[0][j] == 1 && (m[i][1][j] == -1 ? 0 : 1) == 1)) {
				ans[0][j] = 1;
				temp1 = visited[0][j];
				temp1.push_back(m[i][1][j]);
			}
			else if ( (ans[1][j] == 1 && (m[i][0][j] == -1 ? 0 : 1) == 1)) {
				ans[1][j] = 1;
				temp1 = visited[1][j];
				temp1.push_back(m[i][0][j]);
			}

			visited[0][j] = temp0;
			visited[1][j] = temp1;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (ans[1][i] == 1) {
			cout << "TAK\n";
			for (int j = 0; j < N; j++) {
				cout << visited[1][i][j]+1 << ' ';
			}

			return 0;
		}
	}

	cout << "NIE";

	return 0;
}
