#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define pii	pair<int,int>

#define DIR	4
int dy[DIR] = { -1, 0, 1, 0 };
int dx[DIR] = {  0, 1, 0,-1 };


int N, L, R, ans;
int A[50][50];

int abs(int x) {
	return (x > 0 ? x : -x);
}

bool Bfs() { // 변한 값이 있으면 true, 없으면 false 반환
	bool is_changed = false;
	vector<pii> s;

	int ** is_visited;
	is_visited = new int*[N];
	for (int i = 0; i < N; i++) {
		is_visited[i] = new int[N];
		memset(is_visited[i], 0, sizeof(int)*N);
	}

	for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
		if (is_visited[i][j] != 0) continue;

		int sum = 0;
		vector<pii> group;
		s.push_back({ i,j });
		while (!s.empty()) {
			pii cur = s.back(); s.pop_back();
			if (is_visited[cur.first][cur.second] == 0) {
				group.push_back({ cur.first,cur.second });
				sum += A[cur.first][cur.second];
				is_visited[cur.first][cur.second] = 1;

				for (int k = 0; k < DIR; k++) {
					int next_y = cur.first + dy[k], next_x = cur.second + dx[k];
					if (0 <= next_y && next_y < N &&
						0 <= next_x && next_x < N && 
						is_visited[next_y][next_x] == 0) {
						int d = abs(A[cur.first][cur.second] - A[next_y][next_x]);
						if (L <= d && d <= R) s.push_back({ next_y,next_x });
					}
				}
			}
		}

		int num = group.size();
		for (int k = 0; k < num; k++) {
			pii cur = group[k];
			if (A[cur.first][cur.second] != sum / num) is_changed = true;
			A[cur.first][cur.second] = sum / num;
		}
	}
	}

	return is_changed;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		cin >> A[i][j];

	while (Bfs()) { ans++; }
	cout << ans;
	return 0;
}
