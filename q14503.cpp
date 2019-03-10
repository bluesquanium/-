#include <cstdio>
#include <utility>
using namespace std;
#define Point	pair<int,int>
#define DIR	4
int dx[DIR] = { 0, 1, 0,-1};
int dy[DIR] = {-1, 0, 1, 0};

class Cleaner {
public :
	Point point;
	int dir;
	
	Cleaner(Point _point = make_pair(0,0), int _dir = 0) {
		point = _point;
		dir = _dir;
	}
};

int main(void) {
	int n, m, r, c, d, count = 0;
	scanf("%d %d", &n, &m);
	int map[n][m];
	scanf("%d %d %d", &r, &c, &d);
	Cleaner cleaner( make_pair(r,c), d );
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	Point cur = cleaner.point;
	while(1) {
		// 1. 현재 위치를 청소한다. 
		if(map[cleaner.point.first][cleaner.point.second] == 0) {
			count++;
			map[cleaner.point.first][cleaner.point.second] = 2; // 2는 청소했음을 뜻함 
		}
		
		int temp_dir = (DIR + cleaner.dir-1) % DIR;
		bool check_4dir = false; // 4방향 검사해서 빈 곳 있으면 true로. 
		
		// 2. 현재 위치에서 왼쪽방향부터 차례대로 탐색을 진행한다. 
		do{
			int y = cleaner.point.first + dy[temp_dir], x = cleaner.point.second + dx[temp_dir];
			if( 0 <= y && y < n && 0 <= x && x < m ) {
			 	if(map[y][x] == 0) {
			 		check_4dir = true;
			 		cleaner.dir = temp_dir; //방향 업데이트
					cleaner.point = make_pair( y, x ); // 청소기 좌표 업데이트 
					break;
				}
			}
			
			temp_dir = (DIR + temp_dir-1) % DIR;
		}
		while(temp_dir != (DIR + cleaner.dir-1) % DIR);
		
		if(check_4dir == true) continue;
		
		// 3. 네 방향 모두 청소 되있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진하고 2번으로 돌아간다. 
		cleaner.point = make_pair( cleaner.point.first - dy[cleaner.dir], cleaner.point.second - dx[cleaner.dir] );		
		// 4. 네 방향 모두 청소 되있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다. 
		if(map[cleaner.point.first][cleaner.point.second] == 1) break;
	}
	
	printf("%d",count);
	
}
