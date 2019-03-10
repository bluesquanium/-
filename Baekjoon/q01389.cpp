#include <iostream>
using namespace std;
#define INF	99999999

int N, M, a, b, ans = INF, result = -1;
int map[101][101], p[101][101]; // 0Àº ´õ¹Ì

void Init(int N) {
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			map[i][j] = (i!=j?INF:0);
		}
	}
}

int main(void) {
	cin >> N >> M;
	Init(N);
	for(int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
		p[a][b] = a;
		p[b][a] = b;
	}
	
	for(int m = 1; m <= N; m++) {
		for(int s = 1; s <= N; s++) {
			for(int e = 1; e <= N; e++) {
				if(map[s][e] > map[s][m] + map[m][e]) {
					map[s][e] = map[s][m] + map[m][e];
					p[s][e] = p[m][e];
				}
			}
		}
	}
	
	
	for(int i = 1; i <= N; i++) {
		int temp = 0;
		for(int j = 1; j <= N; j++) {
			temp += map[i][j];
		}
		if(ans > temp) {
			ans = temp;
			result = i;
		}
		
	}
	
	/*
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cout << map[i][j] << ' ';
		}cout << endl;
	}cout << endl;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cout << p[i][j] << ' ';
		}cout << endl;
	}
	*/
	
	cout << result;
	
	return 0;
}
