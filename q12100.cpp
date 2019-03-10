#include <iostream>
#include <queue>
using namespace std;

#define DIR	4
int dy[DIR] = {-1, 0, 1, 0};
int dx[DIR] = { 0, 1, 0,-1};
int N, ans;
int m[20][20], move[5]; // 0:위, 1:오른, 2:아래, 3:왼 

void Dfs(int count) {
	if(count < 5) {
		for(int i = 0; i < 4; i++) {
			move[count] = i;
			Dfs(count+1);
			move[count] = -1; 
		}
		return;
	}
	
	int temp_m[N][N];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			temp_m[i][j] = m[i][j];
		}
	}
	
	for(int t = 0; t < 5; t++) {
		if(move[t]==0) {
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N-1; j++) {
					for(int k = j+1; k < N; k++) {
						if(temp_m[j][i] == temp_m[k][i]) {
							temp_m[j][i] *= 2;
							temp_m[k][i] = 0;
							
							j = k;
							break;
						}
						else if(temp_m[k][i] != 0) {
							break;
						}
					}
				}
				
				priority_queue<int, vector<int>, greater<int> > pq;
				for(int j = 0; j < N; j++) { // 한쪽으로 밀어줌 
					if(temp_m[j][i] == 0) {
						pq.push(j);
					}
					if(temp_m[j][i]!=0) {
						if(!pq.empty()) {
							temp_m[pq.top()][i] = temp_m[j][i];
							pq.pop();
							temp_m[j][i] = 0;
							pq.push(j);
						}
					}
				}
			}
		}
		else if(move[t]==2) {
			for(int i = 0; i < N; i++) {
				for(int j = N-1; j > 0; j--) {
					for(int k = j-1; k >= 0; k--) {
						if(temp_m[j][i] == temp_m[k][i]) {
							temp_m[j][i] *= 2;
							temp_m[k][i] = 0;
							
							j = k;
							break;
						}
						else if(temp_m[k][i] != 0) {
							break;
						}
					}
				}
				
				priority_queue<int, vector<int>, less<int> > pq;
				for(int j = N-1; j >= 0; j--) { // 한쪽으로 밀어줌 
					if(temp_m[j][i] == 0) {
						pq.push(j);
					}
					if(temp_m[j][i]!=0) {
						if(!pq.empty()) {
							temp_m[pq.top()][i] = temp_m[j][i];
							pq.pop();
							temp_m[j][i] = 0;
							pq.push(j);
						}
					}
				}
			}
		}
		else if(move[t]==3) {
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N-1; j++) {
					for(int k = j+1; k < N; k++) {
						if(temp_m[i][j] == temp_m[i][k]) {
							temp_m[i][j] *= 2;
							temp_m[i][k] = 0;
							
							j = k;
							break;
						}
						else if(temp_m[i][k] != 0) {
							break;
						}
					}
				}
				
				priority_queue<int, vector<int>, greater<int> > pq;
				for(int j = 0; j < N; j++) { // 한쪽으로 밀어줌 
					if(temp_m[i][j] == 0) {
						pq.push(j);
					}
					if(temp_m[i][j]!=0) {
						if(!pq.empty()) {
							temp_m[i][pq.top()] = temp_m[i][j];
							pq.pop();
							temp_m[i][j] = 0;
							pq.push(j);
						}
					}
				}
			}
		}
		else if(move[t]==1) {
			for(int i = 0; i < N; i++) {
				for(int j = N-1; j >= 1; j--) {
					for(int k = j-1; k >= 0; k--) {
						if(temp_m[i][j] == temp_m[i][k]) {
							temp_m[i][j] *= 2;
							temp_m[i][k] = 0;
							
							j = k;
							break;
						}
						else if(temp_m[i][k] != 0) {
							break;
						}
					}
				}
				
				priority_queue<int, vector<int>, less<int> > pq;
				for(int j = N-1; j >= 0; j--) { // 한쪽으로 밀어줌 
					if(temp_m[i][j] == 0) {
						pq.push(j);
					}
					if(temp_m[i][j]!=0) {
						if(!pq.empty()) {
							temp_m[i][pq.top()] = temp_m[i][j];
							pq.pop();
							temp_m[i][j] = 0;
							pq.push(j);
						}
					}
				}
			}
		}
		
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				ans = max(ans,temp_m[i][j]);
			}
		}
		/*
		for(int x = 0; x < 5; x++) {
			if(move[x]!=2) break;
			if(x==4) {
				for(int y = 0; y < N;y++) {
					for(int z = 0; z < N; z++) {
						cout << temp_m[y][z] << ' ';
					}
					cout << endl;
				}cout << endl;
			}
		}
		*/
	}
	
	return;
}

int main(void) {
	cin >> N;
	for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++)
		cin >> m[i][j];
	
	Dfs(0);
	
	cout << ans;
	
	return 0;
}
