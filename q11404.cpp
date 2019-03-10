#include <iostream>
using namespace std;
#define	INF	98765432

int n, m, a, b, c;
int d[1001][1001];
int p[1001][1001];

void Init(int n) {
	for(int i = 1; i <=n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i!=j) d[i][j] = INF;
		}
	}
	//p[1001][10001]은 0으로 초기화 
}

void Floyd(int n) {
	for(int mid = 1; mid <= n; mid++) {
		for(int s = 1; s <= n; s++) {
			for(int e = 1; e <= n; e++) {
				if(d[s][e] > d[s][mid] + d[mid][e]){
					d[s][e] = d[s][mid] + d[mid][e];
					p[s][e] = p[mid][e];
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	Init(n);
	for(int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if(c < d[a][b]) {
			d[a][b] = c;
			p[a][b] = a; 
		}
	}
	Floyd(n);
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(d[i][j] == INF) cout << "0 ";
			else cout << d[i][j] << ' ';
		}cout << '\n';
	}

	return 0;
}
