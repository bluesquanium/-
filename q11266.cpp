#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX	10001

int V, E, a, b;
vector<int> edge[MAX];
int visited[MAX];
bool isCut[MAX];
int num_visited, num_cut;

int Dfs(int here, bool isRoot) {
	visited[here] = ++num_visited;
	int ret = visited[here];
	int child = 0;
	for(int i = 0; i < edge[here].size(); i++) {
		int next = edge[here][i];
		
		if(visited[next]) { // 이전에 방문한 점일 경우 
			ret = min(ret, visited[next]);
		}
		else {
			child++;
			int prev = Dfs(next, false);
			
			
			if(isRoot!=true&&prev>=visited[here]&&!isCut[here]) {
				num_cut++;
				isCut[here] = true;
			}
			
			ret = min(ret, prev);
		}
	}
	
	if(isRoot==true && child>=2) {
		num_cut++;
		isCut[here] = true;
	}
	
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> V >> E;
	for(int i = 0; i < E; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	for(int i = 1; i <= V; i++) {
		if(visited[i]==0)
			Dfs(i, true);
	}
	/*
	for(int i = 1; i <= V; i++) {
		cout << visited[i] << ' ';
	}
	*/
	
	cout << num_cut << '\n';
	for(int i = 1; i <= V; i++) {
		if(isCut[i]) {
			cout << i << ' ';
		}
	}

	return 0;
}
