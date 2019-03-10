#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
//#define abs(X)	(X)>0?(X):-(X)

int t, n, shortest = 2100000000;
int is_used[12];
vector<int> seq;
vector< pair<int,int> > coordinate;

int abs(int x) {
	return x>0?x:-x;
}

void Dfs(int count) {
	if(count < n) {
		for(int i = 2; i < n+2; i++) {
			if(is_used[i]==0) {
				is_used[i] = 1;
				seq.push_back(i);
				Dfs(count+1);
				is_used[i] = 0;
				seq.pop_back();
			}
		}
		return;
	}
	
	int path = 0;
	path += abs( coordinate[0].first-coordinate[seq[0]].first ) + abs( coordinate[0].second-coordinate[seq[0]].second );
	for(int i = 0; i < n-1; i++) {
		path += abs( coordinate[seq[i]].first-coordinate[seq[i+1]].first ) + abs( coordinate[seq[i]].second-coordinate[seq[i+1]].second );
	}
	path += abs( coordinate[1].first-coordinate[seq[n-1]].first ) + abs( coordinate[1].second-coordinate[seq[n-1]].second );
	
	shortest = min(shortest, path);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	for(int l = 1; l <= t; l++) {
		shortest = 2100000000;
		coordinate.clear();
		seq.clear();
		cin >> n;
		for(int i = 0; i < n+2; i++) { // n+2 : 집, 회사 포함 
			int temp1, temp2;
			cin >> temp1 >> temp2;
			coordinate.push_back( make_pair(temp1, temp2) );
		}
		Dfs(0);
		
		cout << '#' << l << ' ' << shortest << '\n';
	}
	
	return 0;
}
