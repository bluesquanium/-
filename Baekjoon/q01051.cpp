#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	char map[n][m];
	for(int i = 0; i < n; i++) {
		cin >> map[i]; 
	}
	
	int result = 0;
	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < m-1; j++) {
			for(int k = i+1; k < n; k++) {
				for(int l = j+1; l < m; l++) {
					if(map[i][j] != '0') {
						if(map[i][j] ==	map[k][l]) {
							if(map[i][j] == map[k][j] && map[i][j] == map[i][l]) {
								if( (k-i+1) == (l-j+1) )
									result = max(result, (k-i+1)*(l-j+1));
							}
						}
					}
				}
			}
		}
	}
	cout << result;

	return 0;
}
