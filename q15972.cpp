#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = { 0, 1, 0,-1};

int n, m, h, result, tank[1000][1000][5]; // 0:북 1: 동 2: 남 3: 서 (시계방향) 
vector< pair<int,int> > height[1000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> h;
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
		tank[i][j][4] = h; // h로 초기화  
	
	//horizontal
	for(int j = 0; j < m; j++) { // 0
		cin >> tank[0][j][0];
		if(tank[0][j][0] != -1) {
			tank[0][j][4] = tank[0][j][0];
			tank[0][j][0] = -1;
			height[tank[0][j][4]].push_back( make_pair(0, j) );
		}
	}
	for(int i = 1; i < n; i++) { // 1~n-1
		for(int j = 0; j < m; j++) {
			cin >> tank[i][j][0];
			tank[i-1][j][2] = tank[i][j][0];
		}
	}
	for(int j = 0; j < m; j++) { // n
		cin >> tank[n-1][j][2];
		if(tank[n-1][j][2] != -1) {
			tank[n-1][j][4] = tank[n-1][j][2];
			tank[n-1][j][2] = -1;
			height[tank[n-1][j][4]].push_back( make_pair(n-1, j) );
		}
	}
	//vertical
	for(int i = 0; i < n; i++) {
		cin >> tank[i][0][3];
		if(tank[i][0][3] != -1) {
			tank[i][0][4] = tank[i][0][3];
			tank[i][0][3] = -1;
			height[tank[i][0][4]].push_back( make_pair(i, 0) );
		}
		for(int j = 1; j < m; j++) {
			cin >> tank[i][j][3];
			tank[i][j-1][1] = tank[i][j][3];
		}
		cin >> tank[i][m-1][1];
		if(tank[i][m-1][1] != -1) {
			tank[i][m-1][4] = tank[i][m-1][1];
			tank[i][m-1][1] = -1;
			height[tank[i][m-1][4]].push_back( make_pair(i, m-1) );
		}
	}
	
	for(int i = 0; i < h; i++) {
		while(!height[i].empty()) {
			int cur_y = height[i].back().first, cur_x = height[i].back().second;
			height[i].pop_back();
			if( tank[cur_y][cur_x][4] > i ) {
				tank[cur_y][cur_x][4] = i; // 해당 노드에 height값 넣어줌 
			}
			for(int j = 0; j < 4; j++) {
				if( tank[cur_y][cur_x][j] != -1) {
					if( tank[cur_y][cur_x][j] <= i && tank[cur_y+dy[j]][cur_x+dx[j]][4] > i ) {
						tank[cur_y+dy[j]][cur_x+dx[j]][4] = i;
						height[i].push_back( make_pair(cur_y+dy[j], cur_x+dx[j]) );
					}
					else if( tank[cur_y][cur_x][j] > i && tank[cur_y+dy[j]][cur_x+dx[j]][4] > tank[cur_y][cur_x][j] ) {
						tank[cur_y+dy[j]][cur_x+dx[j]][4] = tank[cur_y][cur_x][j];
						height[tank[cur_y][cur_x][j]].push_back( make_pair(cur_y+dy[j], cur_x+dx[j]) );
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
		result += tank[i][j][4];
	
	cout << result;
	return 0;
}
