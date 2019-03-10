#include <iostream>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

int * is_visited;
int V, E, a, b, c, ans;
struct cmp {
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.second > b.second;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> V >> E;
	is_visited = new int[V];
	memset(is_visited,0,sizeof(int)*V);
	
	map<int,int> edge[V];
	priority_queue< pair<int,int>, vector< pair<int,int> >, cmp> pq;
	map<int,int>::iterator iter;
	
	pair<map<int, int>::iterator, bool > pr;
	for(int i = 0; i < E; i++) {
		cin >> a >> b >> c;
	    pr = edge[a-1].insert(make_pair(b-1,c));
	    if (false == pr.second)
	    	edge[a-1][b-1] = min(edge[a-1][b-1], c);
		pr = edge[b-1].insert(make_pair(a-1,c));
	    if (false == pr.second)
	    	edge[b-1][a-1] = min(edge[b-1][a-1], c);
	}
	
	int i = 0; is_visited[i] = 1;
	while(1) {
		for(iter = edge[i].begin(); iter != edge[i].end(); iter++) {
			if(is_visited[(*iter).first] == 0) {
				pq.push((*iter));
			}
		}
		if(pq.empty()) break;
		while(!pq.empty()) {
			pair<int,int> temp = pq.top();
			pq.pop();
			if(is_visited[temp.first]==0) {
				is_visited[temp.first] = 1;
				i = temp.first;
				ans += temp.second;
				break;
			}
		}
	}
	
	cout << ans;
	return 0;
}
