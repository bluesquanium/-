#include <iostream>
using namespace std;

int N, K;
int ** t;
int P[3][20];
int c[3];
int win[3];
int ans;
int is_used[9];

void Input() {
	cin >> N >> K;

	t = new int*[N];
	for (int i = 0; i < N; i++) {
		t[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> t[i][j];
		}
	}

	for (int i = 0; i < 20; i++) {
		cin >> P[1][i];
		P[1][i]--;
	}
	for (int i = 0; i < 20; i++) {
		cin >> P[2][i];
		P[2][i]--;
	}
}

void Dfs(int round, int p1, int p2) {
	if (win[0] == K) {
		ans = 1;
		return;
	}
	else if (win[1] == K || win[2] == K) {
		//ans = -1;
		return;
	}

	if (ans == -1 || ans == 1) {
		return;
	}
	if (3*K-2-round < K-win[0]) {
		return;
	}
	if (p1 == 0) { // 지우가 참여
		for (int i = 0; i < N; i++) {
			if (is_used[i] == 0) {
				is_used[i] = 1;
				if (t[i][P[p2][c[p2]]] == 2) {
					win[0]++;
					c[p2]++;
					Dfs(round + 1, 0, (p2 == 1 ? 2 : 1));
					c[p2]--;
					win[0]--;
				}
				else {
					win[p2]++;
					c[p2]++;
					Dfs(round + 1, 1, 2);
					c[p2]--;
					win[p2]--;
				}
				is_used[i] = 0;
			}
		}
	}
	else { // 지우 참여 x
		if ( t[P[p1][c[p1]]][P[p2][c[p2]]] == 2 ) {
			win[p1]++;
			c[p1]++;
			c[p2]++;
			Dfs(round + 1, 0, p1);
			c[p2]--;
			c[p1]--;
			win[p1]--;
		}
		else {
			win[p2]++;
			c[p1]++;
			c[p2]++;
			Dfs(round + 1, 0, p2);
			c[p2]--;
			c[p1]--;
			win[p2]--;
		}
	}
}

void Print() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << t[i][j] << ' ';
		}cout << endl;
	}cout << endl;
}

int main(void) {
	ios::sync_with_stdio(false);

	Input();

	Dfs(0, 0, 1);

	//Print();
	if (ans == -1 || ans == 0) {
		cout << 0;
	}
	else if (ans == 1) {
		cout << 1;
	}

	//system("pause");
	return 0;
}

