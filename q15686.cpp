#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define abs(X)	((X)>0?(X):-(X))

int N, M, num_c, num_h, ans = 999999999;
int map[51][51], sel_c[13], dist[100]; 
vector< pair<int,int> > h, c;

void Dfs(int count, int prev_c) {
	if(count<M) {
		for(int i = prev_c+1; i < num_c; i++) {
			sel_c[i] = 1;
			Dfs(count+1, i);
			sel_c[i] = 0;
		}
		return;
	}
	
	memset(dist, 4, sizeof(int)*num_h); // init 
	for(int i = 0; i < num_c; i++) {
		if(sel_c[i] == 1) {
			for(int j = 0; j < num_h; j++) {
				dist[j] = min(dist[j], abs(h[j].first-c[i].first)+abs(h[j].second-c[i].second));
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < num_h; i++) sum += dist[i];
	ans = min(ans,sum);
	
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if( map[i][j] == 1) h.push_back( make_pair(i,j) );
			else if( map[i][j] == 2) c.push_back( make_pair(i,j) );
		}
	}
	num_c = c.size(); num_h = h.size();
	
	Dfs(0, -1);
	cout << ans;
	return 0;
}
