#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;
#define Point	pair<int,int>

//동:1, 서:2, 북:3, 남:4
int dx[5] = { 0, 1,-1, 0, 0};
int dy[5] = { 0, 0, 0,-1, 1};

class Dice {
public :
	Point point;
	int state[6]; //0:mid, 1:right, 2:left, 3:above, 4:below, 5:bottom
	
	Dice(Point _point = make_pair(0,0)) {
		point = _point;
		memset(state, 0, sizeof(state));
	}
};

int main(void) {
	int n, m ,x, y, k;
	scanf("%d %d %d %d %d",&n, &m, &x, &y, &k); //글에 써있는 x,y와 내 프로그램의 x,y는 반대임. 조심! 
	Dice dice(make_pair(x,y));
	int map[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d",&map[i][j]);
		}
	}
	for(int i = 0; i < k; i++) {
		int command;
		scanf("%d",&command);
		
		int new_y = dice.point.first + dy[command];
		int new_x = dice.point.second + dx[command];
		if( 0 <= new_y && new_y < n &&
			0 <= new_x && new_x < m ) {
			dice.point = make_pair(new_y, new_x); // 좌표 업데이트
			//주사위 면 업데이트 
			if(command == 1) {
				int temp0 = dice.state[0];
				dice.state[0] = dice.state[2];
				dice.state[2] = dice.state[5];
				dice.state[5] = dice.state[1];
				dice.state[1] = temp0;
			}
			else if(command == 2) {
				int temp0 = dice.state[0];
				dice.state[0] = dice.state[1];
				dice.state[1] = dice.state[5];
				dice.state[5] = dice.state[2];
				dice.state[2] = temp0;
			}
			else if(command == 3) {
				int temp0 = dice.state[0];
				dice.state[0] = dice.state[4];
				dice.state[4] = dice.state[5];
				dice.state[5] = dice.state[3];
				dice.state[3] = temp0;
			}
			else {// command == 4
				int temp0 = dice.state[0];
				dice.state[0] = dice.state[3];
				dice.state[3] = dice.state[5];
				dice.state[5] = dice.state[4];
				dice.state[4] = temp0;
			}
			//바닥면 업데이트
			if(map[new_y][new_x] == 0) {
				map[new_y][new_x] = dice.state[5];
			}
			else {
				dice.state[5] = map[new_y][new_x];
				map[new_y][new_x] = 0;
			}
			
			printf("%d\n",dice.state[0]);
		}
	}
	
	return 0;
}
