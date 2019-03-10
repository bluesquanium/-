#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF	99999999

int N, M, a, b, map[101][101], is_checked[101]; // 0Àº ´õ¹Ì 

void Init(int N) {
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			map[i][j] = (i==j?0:INF);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	cin >> M;
	Init(N);
	for(int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	
	for(int mid = 1; mid <= N; mid++) {
		for(int start = 1; start <= N; start++) {
			for(int end = 1; end <= N; end++) {
				if(map[start][end] > map[start][mid] + map[mid][end]) {
					map[start][end] = map[start][mid] + map[mid][end];
				}
			}
		}
	}
	
	vector<int> ans;
	for(int i = 1; i <= N; i++) {
		if(is_checked[i] == 0) {
			is_checked[i] = true;
			int best = INF, best_i, temp = 0;
			for(int j = 1; j <= N; j++) {
				if(map[i][j]!=INF) {
					is_checked[j] = true;
					temp = 0;
					for(int k =1; k <= N; k++) {
						if(map[j][k] != INF) {
							temp = max(map[j][k],temp);
						}
					}
					if(best>temp) {
						best = temp;
						best_i = j;
					}
				}
			}
			ans.push_back(best_i);	
		}
	}
	
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	/*
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cout << map[i][j] << ' ';
		}cout << '\n';
	}
	*/
	
	return 0;
}
