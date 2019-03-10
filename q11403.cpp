#include <iostream>
using namespace std;
#define INF	98765432
int N, map[100][100], p[100][100];

void Init(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			p[i][j] = -1;
		}
	}
	return;
}

void Floyd(int n) {
	for(int mid = 0; mid < n; mid++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(map[i][j] > map[i][mid] + map[mid][j]) {
					map[i][j] = map[i][mid] + map[mid][j];
					p[i][j] = p[mid][j];
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N;
	Init(N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> map[i][j];
			if(map[i][j] == 0) {
				map[i][j] = INF;
			}
			else {
				p[i][j] = i;
			}
		}
	}
	Floyd(N);
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(map[i][j] >= INF) {
				cout << "0 ";
			}
			else {
				cout << "1 ";
			}
		}cout << endl;
	}

	return 0;
}
