#include <iostream>
#include <queue>
#include <cstring>
#include <functional>
#include <tuple>
using namespace std;
#define	pii	pair<int,int>
#define piii tuple<int,int,int>

#define DIR	4
int dy[DIR] = {-1, 0, 1, 0}; // ¹Ý½Ã°è ¹æÇâ
int dx[DIR] = { 0,-1, 0, 1};

int N, a, s_size, s_exp, ans;
int m[20][20];
pii s;

bool Bfs() {
	queue<pii> q;
	priority_queue< piii, vector<piii>, greater<piii> > pq;
	int step = 1;

	int ** is_visited;
	is_visited = new int*[N];
	for (int i = 0; i < N; i++) {
		is_visited[i] = new int[N];
		memset(is_visited[i], 0, sizeof(int)*N);
	}

	q.push(s);
	while (!q.empty()) {
		queue<pii> temp_q;
		while (!q.empty()) {
			pii cur = q.front(); q.pop();
			is_visited[cur.first][cur.second] = 1;
			for (int i = 0; i < DIR; i++) {
				int next_y = cur.first + dy[i], next_x = cur.second + dx[i];
				if (0 <= next_y && next_y < N &&
					0 <= next_x && next_x < N) {
					if (m[next_y][next_x] == s_size || m[next_y][next_x] == 0) {
						if (is_visited[next_y][next_x] == 0) {
							temp_q.push({ next_y, next_x });
							is_visited[next_y][next_x] = 1;
						}
					}
					else if (m[next_y][next_x] < s_size) {
						if (is_visited[next_y][next_x] == 0) {
							pq.push({ step, next_y, next_x });
							temp_q.push({ next_y, next_x });
							is_visited[next_y][next_x] = 1;
						}
					}
				}
			}
		}
		q = temp_q;
		step++;
	}

	for (int i = 0; i < N; i++) {
		delete[] is_visited[i];
	}
	delete[] is_visited;

	if (!pq.empty()) {
		piii temp = pq.top();
		if (--s_exp == 0) {
			s_size++;
			s_exp = s_size;
		}
		ans += get<0>(temp);
		s = { get<1>(temp), get<2>(temp) };
		m[get<1>(temp)][get<2>(temp)] = 0;
		return true;
	}
	else {
		return false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
			if (m[i][j] == 9) {
				s = { i,j };
				m[i][j] = 0;
			}
		}
	}
	s_size = s_exp = 2;

	while (Bfs()) {}
	cout << ans;

	return 0;
}
