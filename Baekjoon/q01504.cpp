#include <iostream>
#include <queue>
using namespace std;
#define INF	999999999

struct cmp {
	bool operator()( pair<int,long long> a, pair<int,long long> b ) {
		return a.second > b.second;
	}
};

int N, E, A, B, a, b, c;
long long ans;
long long d[801];
vector< pair<int,int> > edge_with[801];
priority_queue< pair<int,long long>, vector< pair<int,long long> >, cmp > pq;

void Dijkstra(int start, int cost) {
	//Init
	for(int i = 1; i <= N; i++) {
		d[i] = INF;
	} d[start] = cost;
	
	//PQ
	pq.push( make_pair(start, cost) );
	while(!pq.empty()) {
		int cur = pq.top().first;
		long long cost = pq.top().second;
		pq.pop();
		if(d[cur] >= cost) {
			for(int i = 0; i < edge_with[cur].size(); i++) {
				int v = edge_with[cur][i].first, w = edge_with[cur][i].second;
				if(d[v] > cost + w) {
					d[v] = cost + w;
					pq.push( make_pair(v,d[v]) );
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N >> E;
	for(int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		edge_with[a].push_back( make_pair(b,c) );
		edge_with[b].push_back( make_pair(a,c) );
	}
	cin >> A >> B;
	
	Dijkstra(1, 0);
	if(d[A] == INF) {
		cout << -1;
		return 0;
	}
	Dijkstra(A, d[A]);
	if(d[B] == INF) {
		cout << -1;
		return 0;
	}
	Dijkstra(B, d[B]);
	if(d[N] == INF) {
		cout << -1;
		return 0;
	}
	ans = d[N];
	
	Dijkstra(1, 0);
	if(d[B] == INF) {
		cout << -1;
		return 0;
	}
	Dijkstra(B, d[B]);
	if(d[A] == INF) {
		cout << -1;
		return 0;
	}
	Dijkstra(A, d[A]);
	if(d[N] == INF) {
		cout << -1;
		return 0;
	}
	ans = min(ans, d[N]);
	
	cout << ans;
	return 0;
}
