#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define Point	pair<int,int>
#define DIR	4

int dy[DIR] = {-1, 0, 1, 0};
int dx[DIR] = { 0, 1, 0,-1};

int n, m, result = 100;
int map[8][8];
vector< pair<Point,int> > cctv;
int cctv_dir[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
int cctv_sight[5][4] = { {1,0,0,0}, {1,0,1,0}, {1,1,0,0}, {1,1,1,0}, {1,1,1,1} };

void Dfs(int count) {
	if(count < cctv.size()) {
		for(int i = 0; i < DIR; i++) {
			cctv_dir[count] = i;
			Dfs(count+1);
			cctv_dir[count] = -1;
		}
		return;
	}
	
	int temp_map[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			temp_map[i][j] = map[i][j];
		}
	}
	
	for(int i = 0; i < cctv.size(); i++) {
		for(int j = 0; j < DIR; j++) {
			if( cctv_sight[cctv[i].second][(j+cctv_dir[i])%4] == 1 ) {
				int new_y = cctv[i].first.first + dy[j], new_x = cctv[i].first.second + dx[j];
				while( 0 <= new_y && new_y < n &&
					   0 <= new_x && new_x < m && 
					   (temp_map[new_y][new_x] != 6) ) {
					if( temp_map[new_y][new_x] == 0 ) {
						temp_map[new_y][new_x] = 7;
					}
					
					new_y += dy[j]; new_x += dx[j];
				}
			}
		}
	}
	
	int num = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(temp_map[i][j] == 0) {
				num++;
			}
		}
	}
	
	result = min(result, num);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> map[i][j];
			if(1 <= map[i][j] && map[i][j] <= 5) {
				cctv.push_back( make_pair( make_pair(i,j), map[i][j]-1 ) ); // cctv ¹øÈ£ 0ºÎÅÍ ¸Å±è 
			}
		}
	}
	
	Dfs(0);
	cout << result;

	return 0;
}
