#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define DIR	4
int dy[DIR] = { -1, 0, 1, 0 };
int dx[DIR] = {  0, 1, 0,-1 };

int N, K, L, a, b, ans;
int m[101][101];
queue< pair<int, int> > command; // { 시간, 방향(-1:좌,1:우) }
queue< pair<int, int> > command_t; // { 시간, 방향(-1:좌,1:우) }

void Dfs() {
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;
	if (K == 0) {
		cout << 1;
		return 0;
	}
	m[1][1] = 1;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		m[a][b] = 2;
	}
	cin >> L;
	b = 0;
	for (int i = 0; i < L; i++) {
		char c;
		cin >> a >> c;
		if (c == 'L') {
			command.push(make_pair(a-b,-1));
		}
		else {
			command.push(make_pair(a-b,1));
		}
		b = a;
	}
	command.push(make_pair(100, 1));

	Dfs();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << m[i][j] << ' ';
		}cout << endl;
	}cout << endl;
	
	cout << ans;
	return 0;
}
