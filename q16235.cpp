#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define pii	pair<int,int>

int N, M, K, x, y, z, ans;
int m[11][11];
int A[11][11]; // 0 is for dummy
deque<int> tree[11][11];
vector<pii> reprod;

#define DIR	8
int dy[DIR] = { -1,-1, 0, 1, 1, 1, 0,-1 };
int dx[DIR] = { 0, 1, 1, 1, 0,-1,-1,-1 };

void Routine() {
	//Spring
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			deque<int>::iterator iter, del_point = tree[i][j].end();
			for (iter = tree[i][j].begin(); iter != tree[i][j].end(); iter++) {
				if (*iter <= m[i][j]) {
					m[i][j] -= *iter;
					*iter += 1;
					if ((*iter) % 5 == 0) {
						reprod.push_back({ i,j });
					}
				}
				else {
					del_point = iter;
					break;
				}
			}
			//Summer
			for (; iter != tree[i][j].end(); iter++) {
				m[i][j] += (*iter) / 2;
			}
			tree[i][j].erase(del_point, tree[i][j].end());
		}
	}
	//Fall
	while (!reprod.empty()) {
		pii cur = reprod.back(); reprod.pop_back();
		for (int i = 0; i < DIR; i++) {
			int next_y = cur.first + dy[i], next_x = cur.second + dx[i];
			if (1 <= next_y && next_y <= N &&
				1 <= next_x && next_x <= N) {
				tree[next_y][next_x].push_front(1);
			}
		}
	}
	//Winter
	for (int i = 1; i <= N; i++)
	for (int j = 1; j <= N; j++)
		m[i][j] += A[i][j];

	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			m[i][j] = 5;
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> y >> x >> z;
		tree[y][x].push_back(z);
	}

	while (K--) {Routine();}

	for (int i = 1; i <= N; i++)
	for (int j = 1; j <= N; j++)
		ans += tree[i][j].size();

	cout << ans;
	return 0;
}
