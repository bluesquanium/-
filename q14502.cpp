#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define Point	pair<int,int>
#define MakePoint(X,Y)	make_pair( (X), (Y) )
#define DIR	4
int dx[DIR] = {0 ,1 ,0 ,-1};
int dy[DIR] = {-1,0 ,1 , 0};

int main(void) {
	int n, m, result = 0;
	scanf("%d %d", &n, &m);
	queue< Point > virus;
	vector< Point > space;
	int map[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j]==0) {
				space.push_back( MakePoint(i,j) );
			}
			else if(map[i][j]==2) {
				virus.push( MakePoint(i,j) );
			}
		}
	}
	//printf("%d %d\n",space.size(), virus.size());
	
	int len = space.size();
	for(int i = 0; i < len-2; i++) {
		for(int j = i+1; j < len-1; j++) {
			for(int k = j+1; k < len; k++) {
				int temp_map[n][m];
				int count = len-3+virus.size();
				for(int l = 0; l < n; l++) {
					for(int p = 0; p < m; p++) {
						temp_map[l][p] = map[l][p];
					}
				}
				temp_map[space[i].first][space[i].second] = 1;
				temp_map[space[j].first][space[j].second] = 1;
				temp_map[space[k].first][space[k].second] = 1;
				
				queue< Point > q = virus;
				while(!q.empty()) {
					count--;
					Point cur = q.front();
					q.pop();
					
					for(int l = 0; l < DIR; l++) {
						if( 0 <= cur.first + dy[l] && cur.first + dy[l] < n && 0 <= cur.second + dx[l] && cur.second + dx[l] < m ) {
							if( temp_map[cur.first + dy[l]][cur.second + dx[l]] == 0 ) {
								temp_map[cur.first + dy[l]][cur.second + dx[l]] = 2; // 2·Î ¹Ù²ãÁÖ±â 
								q.push( MakePoint(cur.first + dy[l], cur.second + dx[l]) );
							}
						}
					}
				}
				result = max(result, count);
			}
		}
	}
	
	printf("%d\n",result);
	/*
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%d ", map[i][j]);
		}
		putchar('\n');
	}
	*/
	
	return 0;
}
