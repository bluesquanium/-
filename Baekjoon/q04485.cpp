#include <iostream>
#include <queue>
using namespace std;
#define INF	99999999
#define DIR	4
int dy[DIR] = {-1, 0, 1, 0};
int dx[DIR] = { 0, 1, 0,-1};

struct cmp {
	bool operator()( pair< int, pair<int,int> > a, pair< int, pair<int,int> > b ) {
		return a.first > b.first;
	}
};

int N, step = 1;
int map[125][125], d[125][125];
priority_queue<pair<int,pair<int,int> >, vector< pair<int,pair<int,int> > >, cmp> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	while(1) {
		cin >> N;
		if(N==0) break;
		
		for(int i = 0; i < N; i++)
		for(int j = 0;j < N; j++)
			d[i][j] = INF;
		for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> map[i][j];
		d[0][0] = map[0][0];
		
		pq.push(make_pair(map[0][0],make_pair(0,0)));
		while(!pq.empty()) {
			int cur_y = pq.top().second.first, cur_x = pq.top().second.second, cost = pq.top().first;
			pq.pop();
			
			if( d[cur_y][cur_x] >= cost ) {
				for(int i = 0; i < DIR; i++) {
					int next_y = cur_y + dy[i], next_x = cur_x + dx[i];
					if( 0 <= next_y && next_y <= N-1 &&
						0 <= next_x && next_x <= N-1 ) {
						if(d[next_y][next_x] > cost + map[next_y][next_x]) {
							d[next_y][next_x] = cost + map[next_y][next_x];
							pq.push(make_pair(d[next_y][next_x],make_pair(next_y,next_x)));
						}
					}
				}
			}
		}		
		cout << "Problem " << step << ": " << d[N-1][N-1] << '\n'; 
		step++;
	}
	return 0;
}
