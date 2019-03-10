#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define INF	99999999

int N, M, a, b, c, d[501];
vector< pair<int,int> > edge_with[501];

void Init(int N) {
	for(int i = 1; i <= N; i++) d[i] = INF;
	d[1] = 0;
}

int BellmanFord(int N) {
	for(int t = 1; t <= N; t++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j < edge_with[i].size(); j++) {
				int new_val = d[i] + edge_with[i][j].second;
				int before_val = d[edge_with[i][j].first];
				if( (d[i] != INF) && (new_val < before_val) ) {
					if(t==N) return -1;
					d[edge_with[i][j].first] = new_val;
				}
			}
		}
	}
	return 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N >> M;
	Init(N);
	for(int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		edge_with[a].push_back( make_pair(b,c) );
	}
	
	BellmanFord(N);
	if(BellmanFord(N) == -1) cout << -1;
	else {
		for(int i = 2; i <= N; i++) {
			if(d[i]==INF) cout << "-1\n";
			else cout << d[i] << '\n';
		}
	}
	
	
	return 0;
}
