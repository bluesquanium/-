#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int dx[8] = { 0, 1, 1, 1, 0,-1,-1,-1}; // �ð����
int dy[8] = {-1,-1, 0, 1, 1, 1, 0,-1};

int main(void) {
	int w, h = -1;
	while( !(w == 0 && h == 0) ) {
		cin >> w >> h;
		
		if(w == 0 && h == 0) {
			break;
		}
		
		char map[h][w];
		
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		
		//�˰���
		int count = 0;
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				if(map[i][j] == '1') {
					count++;
					
					map[i][j] = '0'; // 0���� �ٲ��ֱ� 
					vector< pair<int,int> > s;
					s.push_back(make_pair(i,j));
					
					while(!s.empty()) {
						pair<int,int> cur = s.back();
						s.pop_back();
						for(int k = 0; k < 8; k++) {
							if( 0 <= cur.first + dy[k] && cur.first + dy[k] < h && 0 <= cur.second + dx[k] && cur.second + dx[k] < w ) {
								if( map[cur.first + dy[k]][cur.second + dx[k]] == '1' ) {
									map[cur.first + dy[k]][cur.second + dx[k]] = '0'; // 0���� �ٲ��ֱ� 
									s.push_back( make_pair(cur.first + dy[k], cur.second + dx[k]) );
								}
							}
						} 
					}
				}
			}
		}
		
		//�� ���� ���
		cout << count << endl; 
	}
	
	return 0;
}
