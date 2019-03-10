#include <iostream>
using namespace std;

int N, Q, s, e, C, map[101][101]; // 0Àº ´õ¹Ì

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> Q;
	for(int i = 0; i < Q; i++) {
		cin >> s >> e;
		map[s][e] = 1;
		map[e][s] = 1;
	}
	
	for(int m = 1; m <= N; m++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				map[i][j] |= map[i][m]&&map[m][j];
			}
		}
	}
	
	for(int j = 2; j <= N; j++) {
		if(map[1][j] == 1) {
			C++;
		}
	}
	
	cout << C;
	
	return 0;
}
