/*
 *DFS를 이용한 백트래킹 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define Abs(X,Y)	( (X)>(Y)?(X)-(Y):(Y)-(X) )

#define MAX	21
int n;
bool is_used[MAX];
int stat[MAX][MAX];
int ans = 2147483647;

void Dfs(int cur_player, int cnt) {
	if(cnt != n/2) {
		//if(is_used[0] == true) cout << "hey!\n";
		for(int i = cur_player+1; i < n; i++) {
			if(is_used[i] == false) {
				is_used[i] = true;
				Dfs(i, cnt+1);
				is_used[i] = false;
			}
		}
		return;
	}
	
	vector<int> team_start, team_link;
	for(int i = 0; i < n; i++) {
		if( is_used[i] ) team_start.push_back(i);
		else team_link.push_back(i);
	}
	
	int stat_start = 0, stat_link = 0;
	for(int i = 0; i < n/2; i++) {
		for(int j = i+1; j < n/2; j++) {
			stat_start += stat[team_start[i]][team_start[j]] + stat[team_start[j]][team_start[i]];
			stat_link += stat[team_link[i]][team_link[j]] + stat[team_link[j]][team_link[i]];
		}
	}
	
	ans = min(ans, abs(stat_start - stat_link));
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> stat[i][j];
		}
	}
	
	Dfs(-1, 0);
	
	cout << ans << '\n';
	
	
	
	return 0;
}
