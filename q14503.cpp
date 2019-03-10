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
		// 1. ���� ��ġ�� û���Ѵ�. 
		if(map[cleaner.point.first][cleaner.point.second] == 0) {
			count++;
			map[cleaner.point.first][cleaner.point.second] = 2; // 2�� û�������� ���� 
		}
		
		int temp_dir = (DIR + cleaner.dir-1) % DIR;
		bool check_4dir = false; // 4���� �˻��ؼ� �� �� ������ true��. 
		
		// 2. ���� ��ġ���� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�. 
		do{
			int y = cleaner.point.first + dy[temp_dir], x = cleaner.point.second + dx[temp_dir];
			if( 0 <= y && y < n && 0 <= x && x < m ) {
			 	if(map[y][x] == 0) {
			 		check_4dir = true;
			 		cleaner.dir = temp_dir; //���� ������Ʈ
					cleaner.point = make_pair( y, x ); // û�ұ� ��ǥ ������Ʈ 
					break;
				}
			}
			
			temp_dir = (DIR + temp_dir-1) % DIR;
		}
		while(temp_dir != (DIR + cleaner.dir-1) % DIR);
		
		if(check_4dir == true) continue;
		
		// 3. �� ���� ��� û�� ���ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ �����ϰ� 2������ ���ư���. 
		cleaner.point = make_pair( cleaner.point.first - dy[cleaner.dir], cleaner.point.second - dx[cleaner.dir] );		
		// 4. �� ���� ��� û�� ���ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����. 
		if(map[cleaner.point.first][cleaner.point.second] == 1) break;
	}
	
	printf("%d",count);
	
}
