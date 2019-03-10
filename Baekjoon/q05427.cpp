#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define DIR	4
int dy[DIR] = {-1, 0, 1, 0};
int dx[DIR] = { 0, 1, 0,-1};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, w, h;
	cin >> t;
	while(t--) {
		vector< pair<int,int> > fire, sg; // 불 번지기 전 지점 
		cin >> w >> h;
		char map[h][w];
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				cin >> map[i][j];
				if(map[i][j] == '*') {
					map[i][j] = '#';
					fire.push_back(make_pair(i,j)); // 초기 불 위치 저장 
				}
				else if(map[i][j] == '@') { // 초기 상근이 위치 
					map[i][j] = '.';
					sg.push_back( make_pair(i,j) );
				}
			}
		}
		if( !sg.empty() && (sg[0].first == 0 || sg[0].first == h-1 || sg[0].second == 0 || sg[0].second == w-1) ) {
			cout << 1 << '\n';
			continue;
		}
		
		int step = 1;
		bool possible = false;
		while(!sg.empty()) {
			step++;
			vector< pair<int,int> > smoke, sg2;
			while(!fire.empty()) {
				pair<int,int> cur = fire.back();
				fire.pop_back();
				for(int i = 0; i < DIR; i++) {
					int y_new = cur.first + dy[i], x_new = cur.second + dx[i];
					if( 0 <= y_new && y_new < h &&
						0 <= x_new && x_new < w ) {
						if( map[y_new][x_new] == '.' ) {
							smoke.push_back( make_pair(y_new, x_new) );
							map[y_new][x_new] = '#';
						}
					}
				}
			}
			while(!sg.empty()) {
				pair<int,int> cur = sg.back();
				sg.pop_back();
				for(int i = 0; i < DIR; i++) {
					int y_new = cur.first + dy[i], x_new = cur.second + dx[i];
					if( 0 <= y_new && y_new < h &&
						0 <= x_new && x_new < w ) {
						if( map[y_new][x_new] == '.' ) {
							sg2.push_back( make_pair(y_new, x_new) );
							map[y_new][x_new] = '#';
							
							if( y_new == 0 || y_new == h-1 || x_new == 0 || x_new == w-1 ) {
								possible = true;
								break;
							}
						} 
					}
				}
				if(possible) break;
			}
			if(possible) break;
			fire = smoke;
			sg = sg2;
		}
		
		if(possible) cout << step << '\n';
		else 		 cout << "IMPOSSIBLE\n";
	}

	return 0;
}
