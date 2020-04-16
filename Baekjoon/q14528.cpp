#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, M, rd, ans;
vector<string> m;
enum {
	A = 'A', C = 'C', G = 'G', T = 'T'
};
int checklist[64];

int abs(int num) {
	return num > 0 ? num : -num;
}

int makeNum(int a, int b, int c) {
	int num = a;
	num = num << 2;
	num += b;
	num = num << 2;
	num += c;
	return num;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	m.resize(N * 2);
	for (int i = 0; i < N * 2; i++) {
		cin >> m[i];
	}
	for (int i = 0; i < N * 2; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] == A) {
				m[i][j] = 0;
			} else if (m[i][j] == C) {
				m[i][j] = 1;
			} else if (m[i][j] == G) {
				m[i][j] = 2;
			}
			else  if (m[i][j] == T){
				m[i][j] = 3;
			}
			else {
				return -1;
			}
		}
	}


	for (int a = 0; a < M-2; a++) {
		for (int b = a+1; b < M-1; b++) {
			for (int c = b+1; c < M; c++) {
				int check = 1;
				rd++;
				for (int i = 0; i < N; i++) {
					checklist[makeNum(m[i][a], m[i][b], m[i][c])] = rd;
				}
				for (int i = N; i < N * 2; i++) {
					if (checklist[makeNum(m[i][a],m[i][b],m[i][c])] == rd) {
						check = 0;
						break;
					}
				}
				ans += check;
			}
		}
	}

	cout << ans;

	return 0;
}
