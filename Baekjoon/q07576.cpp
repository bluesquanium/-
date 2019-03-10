#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define DIR	4
int dx[4] = { 0, 1, 0,-1};
int dy[4] = {-1, 0, 1, 0};

int main(void) {
	//Input
	queue< pair<int,int> > q;
	int m, n, step;
	cin >> m >> n;
	int map[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> map[i][j];
			if(map[i][j]==1) { // 1 나올 때마다 q에 저장 
				q.push( make_pair(i,j) );
			}
		}
	}
	
	//Algorithm
	step = -1;
	while(!q.empty()) {
		step += 1; // 매번 while문 반복 시 step 1씩 늘려간다. 
		queue< pair<int,int> > temp_q;
		while(!q.empty()) {
			pair<int,int> cur = q.front();
			q.pop();
			
			for(int i = 0; i < DIR; i++) {
				if( 0 <= cur.first + dy[i] && cur.first + dy[i] < n && 0 <= cur.second + dx[i] && cur.second + dx[i] < m ) {
					if( map[cur.first + dy[i]][cur.second + dx[i]] == 0 ) {
						temp_q.push( make_pair(cur.first + dy[i], cur.second + dx[i]) );
						map[cur.first + dy[i]][cur.second + dx[i]] = 1;
					}
				}
			}
		}
		q = temp_q;
	}
	
	//map에 0이 남아있는지 확인 
	for(int i = 0; i < n; i++) {
		for(int j =0; j < m; j++) {
			if(map[i][j] == 0) { // 0이 남아있다면 step = -1 저장 
				step = -1;
				break;
			}
		}
	}
	cout << step;
	
	return 0;
}
