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
	A='A', C='C', G='G', T='T'
};
int checklist[4];

int abs(int num) {
	return num > 0 ? num : -num;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	m.resize(N * 2);
	for (int i = 0; i < N * 2; i++) {
		cin >> m[i];
	}

	for (int i = 0; i < M; i++) {
		int check = 1;
		rd++;
		for (int j = 0; j < N; j++) {
			checklist[m[j][i]] = rd;
		}
		for (int j = N; j < N * 2; j++) {
			if (checklist[m[j][i]] == rd) {
				check = 0;
				break;
			}
		}
		ans += check;
	}

	cout << ans;

	return 0;
}
