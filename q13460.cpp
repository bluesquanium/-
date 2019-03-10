#include <iostream>
using namespace std;

int N, M;

int main(void) {
	cin >> N >> M;
	char m[N][M];
	
	for(int i = 0; i < N; i++) {
		cin >> m[i];
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cout << m[i][j];	
		}cout << endl;
	}
	
	return 0;
}
