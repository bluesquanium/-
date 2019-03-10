#include <iostream>
#include <cstring>
using namespace std;
#define DIR	4

int map[101][101];
//0:동, 1:북, 2:서, 3:남

int dy[DIR] = { 0,-1, 0, 1};
int dx[DIR] = { 1, 0,-1, 0};

int main(void) {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int y, x, d, g;
		cin >> y >> x >> d >> g; // y, x 반대로 받음.
		
		int temp[201][201];
		memset(temp, 0, sizeof(int)*201*201);
		/*
		for(int j = 0;j < 201; j++) {
			for(int k = 0; k < 201; k++) {
				cout << temp[j][k] << ' ';
			}
			cout << endl;
		}
		*/
		temp[100][100] = 1;
		temp[100][101] = 1;
		for(int l = 0; l < g; l++) {
			for(int j = 0; j < 201; j++) {
				for(int k = 0; k < 201; k++) {
					if( temp[j][k] == 1 ) {
						temp[k][200-j] = 1;
					}
				}
			}
		}
		
		for(int j = 0;j < 101; j++) {
			for(int k = 0; k < 101; k++) {
				map[i][j] = temp[i+100-y][j+100-x];
			}
		}
		
		cout << temp[100][101] << temp[100][100] << endl;
		//cout << temp[
		
		
		for(int j = 80; j < 120; j++) {
			for(int k = 80; k < 120; k++) {
				cout << temp[j][k] << ' ';
			}
			cout << endl;
		}
		
		
		/*
		for(int j = 0; j < 101; j++) {
			for(int k = 0; k < 101; k++) {
				cout << map[j][k] << ' ';
			}
			cout << endl;
		}
		*/
		
	}

	return 0;
}
