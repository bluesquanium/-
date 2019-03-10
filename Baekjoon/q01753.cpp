#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF	99999999

int main(void) {
	int V, E, K, u, v, w;
	cin >> V >> E >> K;
	int d[V+1];
	vector< pair<int,int> > edge_with[V+1];
	priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
	
	for(int i = 1; i <= V; i++) d[i] = INF;
	d[K] = 0;
	for(int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		edge_with[u].push_back(make_pair(v, w));
	}
	
	pq.push( make_pair(0,K) );
	while(!pq.empty()) {
		int cost = pq.top().first, cur = pq.top().second;
		pq.pop();
		
		if(cost <= d[cur]) {
			for(int i = 0; i < edge_with[cur].size(); i++) {
				v = edge_with[cur][i].first;
				w = edge_with[cur][i].second;
				if(d[v] > cost + w) {
					d[v] = cost +w;
					pq.push( make_pair(d[v],v) );
				}
			}
		}
	}
	
	for(int i = 1; i <= V; i++) {
		if(d[i] != INF) {
			cout << d[i] << '\n';
		}
		else {
			cout << "INF\n";
		}
	}
	
	return 0;
}
