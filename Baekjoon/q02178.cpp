#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dx[8] = { 0, 1, 0,-1}; // �ð����
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
	maze[0][0].second = 0; // ó�� Ž������ ��ġ�� maze[0][0].second�� -1�� �ƴ� 0���� ����. 
	
	//�˰���
	queue< pair<int,int> > q;
	q.push( make_pair(0,0) );
	
	step = 0;
	while(!q.empty()) {
		step += 1; // �Ź� while�� �ݺ� �� step 1�� �÷�����. 
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
						maze[cur.first + dy[i]][cur.second + dx[i]].second = step+1; // �� ���� ��. �ٸ� ����Ƚ�� �� ���̷��� ����. 
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
