#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dx[8] = { 0, 1, 0,-1}; // 시계방향
int dy[8] = {-1, 0, 1, 0};

int main(void) {
	int n, m, step;
	cin >> n >> m;
	
	pair<char, int> maze[n][m];
	for(int i = 0; i < n; i++) {
		char * temp = new char[m];
		cin >> temp;
		
		for(int j = 0; j < m; j++) {
			maze[i][j] = make_pair(temp[j], -1);
		}
		
		delete temp;
	}
	maze[0][0].second = 0; // 처음 탐색시작 위치인 maze[0][0].second는 -1이 아닌 0으로 저장. 
	
	//알고리즘
	queue< pair<int,int> > q;
	q.push( make_pair(0,0) );
	
	step = 0;
	while(!q.empty()) {
		step += 1; // 매번 while문 반복 시 step 1씩 늘려간다. 
		queue< pair<int,int> > temp_q;
		while(!q.empty()) {
			pair<int,int> cur = q.front();
			q.pop();
			
			if( cur.first == n-1 && cur.second == m-1 ) {
				cout << step;
				return 0;
				//break;
			}
			
			for(int i = 0; i < 4; i++) {
				if( 0 <= cur.first + dy[i] && cur.first + dy[i] < n && 0 <= cur.second + dx[i] && cur.second + dx[i] < m ) {
					if( maze[cur.first + dy[i]][cur.second + dx[i]].first == '1' &&
						maze[cur.first + dy[i]][cur.second + dx[i]].second == -1 ) {
						maze[cur.first + dy[i]][cur.second + dx[i]].second = step+1; // 얜 빼도 됨. 다만 연산횟수 좀 줄이려고 넣음. 
						temp_q.push( make_pair(cur.first + dy[i], cur.second + dx[i]) );
					}
				}
			}	
		}
		q = temp_q;
	}
	
	cout << -1;
	
	return 0;
}
