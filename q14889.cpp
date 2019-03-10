#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define Abs(X,Y)	( (X)>(Y)?(X)-(Y):(Y)-(X) )

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int n, result = 2100000000;
	cin >> n;
	int stat[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> stat[i][j];
		}
	}
	
	vector<int> team_a;
	for(int i = 0; i < n/2; i++) {
		team_a.push_back(i);
	}
	while(!team_a.empty()) {
		if (team_a.size() != n/2) { // 팀 멤버가 n/2가 만족되지 않았다면 팀원 추가한다. 
			if(team_a.back() + 1 + (n/2-team_a.size()) < n) { // 범위 넘어가지 않음. 
				team_a.back() += 1;
				
				int need = n/2-team_a.size();
				for(int i = 0; i < need; i++) {
					team_a.push_back(team_a.back() + 1);
				}	
			}
			else {
				team_a.pop_back();
				continue;
			} 
		}
		
		int cur = 0;
		vector<int> team_b;
		for(int i = 0; i < n; i++) {
			if(team_a[cur] != i) {
				team_b.push_back(i);
			}
			else cur++;
		}
		
		int score_a = 0, score_b = 0;
		for(int i = 0; i < n/2; i++) {
			for(int j = 0; j < n/2; j++) {
				if(i != j){
					score_a += stat[team_a[i]][team_a[j]];
					score_b += stat[team_b[i]][team_b[j]];
				}
			}
		}
		
		result = min(result, Abs(score_a, score_b));
		
		if(team_a.back()+1 < n) {
			team_a.back() += 1;
		}
		else {
			team_a.pop_back();
		}
	}
	
	cout << result << '\n';
	
	
	
	return 0;
}
