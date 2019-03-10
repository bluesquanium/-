#include <iostream>
#include <queue>
using namespace std;
#define INF	999999999

struct cmp {
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.second > b.second;
	}
};


int N, M, S, E, a, b, w;
int d[1001];
vector< pair<int,int> > edge_with[1001];
priority_queue< pair<int,int>, vector< pair<int,int> >, cmp> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		d[i] = INF;
	}
	for(int i = 0; i < M; i++) {
		cin >> a >> b >> w;
		edge_with[a].push_back( make_pair(b,w) );
	}
	cin >> S >> E;
	d[S] = 0;
	
	pq.push( make_pair(S,0) );
	while(!pq.empty()) {
		int cur = pq.top().first, cost = pq.top().second;
		pq.pop();
		
		if(cost <= d[cur]) {
			for(int i = 0; i < edge_with[cur].size(); i++) {
				pair<int,int> next = edge_with[cur][i];
				if( d[next.first] > cost + next.second ) {
					d[next.first] = cost + next.second;
					pq.push( make_pair(next.first,d[next.first]) );
				}
			}
		}
	}
	
	cout << d[E];
	
	return 0;
}
