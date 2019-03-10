#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, H, a, b, ans = 4;
int edge[11][31]; // edge[i][j] : i번째 사다리의 오른쪽 방향 j 번째 다리 

void Dfs(int count) {
	if(ans<=count) return;
	
	bool check = true;
	int c = 0;
	// 정답 만족하는지 확인 
	for(int i = 1; i <= N; i++) {
		int cur = i;
		for(int j = 1; j <= H; j++) {
			if(edge[cur][j]==1) cur++;
			else if(edge[cur-1][j]==1) cur--;
		}
		if(cur!=i) {
			check = false;
			c++;
		}
	}
	if(c>(3-count)*2) return;
	else if(check==true) ans = min(ans, count);
	else {
		if(count<3) {
			for(int i = 1; i < N; i++)
			for(int j = 1; j <= H; j++)
				if(edge[i][j]==0 && edge[i-1][j]==0) {
					edge[i][j] = 1;
					Dfs(count+1);
					edge[i][j] = 0;
				}
		}
	}
	
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> H;
	if(M==0) {
		cout << 0;
		return 0;
	}
	
	for(int i = 0; i < M; i++) {
		cin >> a >> b;
		edge[b][a] = 1; 
	}
	
	Dfs(0);
	if(ans==4) cout << -1;
	else cout << ans;
	
	return 0;
}
