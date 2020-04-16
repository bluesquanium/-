#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll W, N, ans;
vector<ll> m;

int mem[800000][4][2];
int memNum[800000];

int check(int num1) {
	int num2 = W - num1;
	if (memNum[num1] > 4 && memNum[num2] > 4) {
		return 1;
	}

	for (int i = 0; i < memNum[num1] && i < 4; i++) {
		for (int j = 0; j < memNum[num2] && j < 4; j++) {
			if (mem[num1][i][0] != mem[num2][j][0] && mem[num1][i][0] != mem[num2][j][1] &&
				mem[num1][i][1] != mem[num2][j][0] && mem[num1][i][1] != mem[num2][j][1]) {
				return 1;
			}
		}
	}

	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> W >> N;
	m.resize(N);
	
	for (int i = 0; i < N; i++) {
		cin >> m[i];
	}
	sort(m.begin(), m.end());

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int sum = m[i] + m[j];
			if (memNum[sum] < 4) {
				mem[sum][memNum[sum]][0] = i;
				mem[sum][memNum[sum]][1] = j;
			}
			memNum[sum]++;
		}
	}

	for (int i = 1; i < W; i++) {
		if (memNum[i] && memNum[W - i]) {
			if (check(i)) {
				ans = 1;
				break;
			}
		}
	}



	if (ans) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}
