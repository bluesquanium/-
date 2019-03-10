#include <iostream>
#include <algorithm>
using namespace std;

#define DIR	3
int dy[DIR] = {-1, 0, 1};
int dx[DIR] = { 0, 1, 0};
int lastblock[4][4] = { {1,0+500,1+500,2+500}, {0,0+500,1+500,0+2*500}, {0,1,2,1+500}, {1,0+500,1+500,1+2*500} };

int n, m, result = 0;
int map[500][500];
bool is_used[500][500];

void Dfs(int y, int x, int count, int value) {
	if(count < 4) {
		for(int i = 0; i < DIR; i++) {
			int new_y = y + dy[i], new_x = x + dx[i];
			if( 0 <= new_y && new_y < n &&
				0 <= new_x && new_x < m ) {
				if( is_used[new_y][new_x] == false ) {
					is_used[new_y][new_x] = true;
					Dfs(new_y, new_x, count+1, value+map[new_y][new_x]);
					is_used[new_y][new_x] = false;
				}
			}
		}
		return;
	}
	
	result = max(result, value);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			Dfs(i, j-1, 0, 0);
			for(int k = 0; k < 4; k++) { 
				if( (n-1)*500 + m > i*500+j + lastblock[k][3] ) {
					int value = 0;
					for(int l = 0; l < 4; l++) {
						value += *(*map+ i*500+j + lastblock[k][l]);
					}
					result = max(result, value);
				}
			}
		}
	}
	
	cout << result;

	return 0;
}
