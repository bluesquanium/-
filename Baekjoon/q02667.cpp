#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 1, 0,-1};
int dy[4] = {-1, 0, 1, 0};

int main(void) {
	int n;
	cin >> n;
	char map[n][n];
	for(int i = 0; i < n; i++) {
		cin >> map[i];
	}
	
	//알고리즘
	int total = 0;
	vector<int> result;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int count = 0;
			if(map[i][j] == '1') {
				total++;
				
				map[i][j] = '0'; // 0으로 바꿔주기 
				vector< pair<int,int> > s;
				s.push_back(make_pair(i,j));
				
				while(!s.empty()) {
					count++;
					pair<int,int> cur = s.back();
					s.pop_back();
					for(int k = 0; k < 4; k++) {
						if( 0 <= cur.first + dy[k] && cur.first + dy[k] < n && 0 <= cur.second + dx[k] && cur.second + dx[k] < n ) {
							if( map[cur.first + dy[k]][cur.second + dx[k]] == '1' ) {
								map[cur.first + dy[k]][cur.second + dx[k]] = '0'; // 0으로 바꿔주기 
								s.push_back( make_pair(cur.first + dy[k], cur.second + dx[k]) );
							}
						}
					} 
				}
			}
			if(count!=0) result.push_back(count);
		}
	}
	sort(result.begin(),result.end());
	
	cout << total << endl;
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	
	return 0;
}
