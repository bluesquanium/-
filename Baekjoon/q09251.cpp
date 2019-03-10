#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void) {
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.length(), m = s2.length();
	
	int map[n][m];
	memset(map, 0, sizeof(map));
	
	for(int i = 0; i < n; i++) {
		if(s1[i] == s2[0])
			map[i][0] = 1;
		else if(i > 0) {
			if(map[i-1][0] == 1)
				map[i][0] = 1;
		}
	}
	for(int j = 0; j < m; j++) {
		if(s2[j] == s1[0])
			map[0][j] = 1;
		else if(j > 0) {
			if(map[0][j-1] == 1)
				map[0][j] = 1;
		}
	}
	
	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(s1[i] == s2[j])
				map[i][j] = map[i-1][j-1] + 1;
			else
				map[i][j] = max(max(map[i-1][j-1], map[i-1][j]), map[i][j-1]);
		}
	}
	
	/*
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	
	
	cout << map[n-1][m-1];
	
	return 0;
}
