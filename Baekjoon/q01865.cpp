#include <iostream>
using namespace std;
#define INF 999999999

int T, N, M, W, s, e, t;
int map[501][501];

void Init(int N) {
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			map[i][j] = (i==j?0:INF);
		}
	}
}

void Floyd(int N) {
	for(int mid = 1; mid <= N; mid++) {
		for(int s = 1; s <= N; s++) {
			for(int e = 1; e <= N; e++) {
				if(map[s][mid] != INF && map[mid][e] != INF) {
					if(map[s][e] > map[s][mid] + map[mid][e]) {
						map[s][e] = map[s][mid] + map[mid][e];
					}
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	while(T--) {
		cin >> N >> M >> W;
		Init(N);
		for(int i = 0; i < M; i++) {
			cin >> s >> e >> t;
			if(map[s][e] > t) map[s][e] = t;
			if(map[e][s] > t) map[e][s] = t;
		}
		for(int i = 0; i < W; i++) {
			cin >> s >> e >> t;
			if(map[s][e] > -t) map[s][e] = -t;
		}
		Floyd(N);
		
		bool check = false;
		for(int i = 1; i <= N; i++) {
			if(map[i][i] < 0) {
				cout << "YES\n";
				check = true;
				break;
			}
		}
		if(check == false) {
			cout << "NO\n";
		}
	}
	return 0;
}
