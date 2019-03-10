#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
#define DIR	6
int dz[DIR] = { 0, 0, 0, 0,-1, 1 };
int dy[DIR] = { -1, 0, 1, 0, 0, 0 };
int dx[DIR] = { 0, 1, 0,-1, 0, 0 };

int ans = 126;
int temp[5][5][5];
int m[5][4][5][5];
int phase_selected[5];

void Input() {
	for (int i = 0; i < 5; i++)
	for (int j = 0; j < 5; j++)
	for (int k = 0; k < 5; k++)
		cin >> temp[i][j][k];
}

void Rotate(int phase, int r) { // r==0 -> cw, r==1 -> rcw 
	int temp_m[5][5];

	for (int i = 0; i < 5; i++)
	for (int j = 0; j < 5; j++)
		temp_m[i][j] = temp[phase][i][j];

	if(r==0) {
		for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			temp[phase][j][4 - i] = temp_m[i][j];
	}
	else if(r==1) {
		for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			temp[phase][i][j] = temp_m[j][4 - i];
	}
	
}

void MakeMap() {
	for (int phase = 0; phase < 5; phase++) {
		for (int i = 0; i < 4; i++) {
			Rotate(phase, 0);
			for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				m[phase][i][j][k] = temp[phase][j][k];
		}
	}
}

void Dfs(int count) {
	if (ans == 12) return;

	if (count < 5) {
		for (int i = 0; i < 5; i++) {
			if (phase_selected[i] == 0) {
				phase_selected[i] = 1;
				for (int j = 0; j < 4; j++) {
					for (int k = 0; k < 5; k++)
					for (int l = 0; l < 5; l++)
						temp[count][k][l] = m[i][j][k][l];
					if (temp[0][0][0] == 1) Dfs(count + 1);
				}
				phase_selected[i] = 0;
			}
		}
	}
	else {
		if (temp[4][4][4] == 0) return;
		
		int step = 0, possible = -1;
		int is_visited[5][5][5] = { 0, };
		queue< tuple<int, int, int> > q;
		
		q.push({ 0,0,0 });
		while (!q.empty()) {
			queue< tuple<int, int, int> > temp_q;
			while (!q.empty()) {
				tuple<int, int, int> cur = q.front(); q.pop();
				if (get<0>(cur) == 4 && get<1>(cur) == 4 && get<2>(cur) == 4) {
					ans = min(ans, step);
					return;
				}

				if (is_visited[get<0>(cur)][get<1>(cur)][get<2>(cur)] == 0) {
					is_visited[get<0>(cur)][get<1>(cur)][get<2>(cur)] = 1;

					for (int i = 0; i < DIR; i++) {
						int next_z = get<0>(cur) + dz[i],
							next_y = get<1>(cur) + dy[i],
							next_x = get<2>(cur) + dx[i];
						if (0 <= next_z && next_z < 5 &&
							0 <= next_y && next_y < 5 &&
							0 <= next_x && next_x < 5) {
							if (is_visited[next_z][next_y][next_x] == 0 &&
								temp[next_z][next_y][next_x] == 1) {
								temp_q.push({ next_z,next_y,next_x });
							}
						}
					}
				}
			}
			q = temp_q;
			step++;
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Input();
	MakeMap();
	Dfs(0);

	if (ans == 126) cout << -1;
	else cout << ans;
	return 0;
}
