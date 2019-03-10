#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <functional>
using namespace std;
#define pii	pair<int,int>
#define piii tuple<int,int,int>

#define DIR	8
int dy[DIR] = { -1,-1, 0, 1, 1, 1, 0,-1 };
int dx[DIR] = {  0, 1, 1, 1, 0,-1,-1,-1 };

//F:0 U:1 R:2 D:3 L:4 B:5
//+:cw, -:rcw

char cube[6][9] = { {'r','r','r','r','r','r','r','r','r'},
					{'w','w','w','w','w','w','w','w','w'},
					{'b','b','b','b','b','b','b','b','b'},
					{'y','y','y','y','y','y','y','y','y'},
					{'g','g','g','g','g','g','g','g','g'},
					{'o','o','o','o','o','o','o','o','o'} };
/*
char cube[6][9] = { { 'r','w','b','b','y','y','g','o','w' },
					{ 'w','w','w','w','w','w','w','w','w' },
					{ 'b','b','b','b','b','b','b','b','b' },
					{ 'y','y','y','y','y','y','y','y','y' },
					{ 'g','g','g','g','g','g','g','g','g' },
					{ 'o','o','o','o','o','o','o','o','o' } };
*/

int T, n;

void Init() {
	for (int s = 0; s < 6; s++) {
		for (int i = 0; i < 9; i++) {
			if (s == 0) {
				cube[s][i] = 'r';
			}
			else if (s == 1) {
				cube[s][i] = 'w';
			}
			else if (s == 2) {
				cube[s][i] = 'b';
			}
			else if (s == 3) {
				cube[s][i] = 'y';
			}
			else if (s == 4) {
				cube[s][i] = 'g';
			}
			else if (s == 5) {
				cube[s][i] = 'o';
			}
		}
	}
}

void Cw(int side) {
	char temp_side[9];
	for (int i = 0; i < 9; i++) {
		temp_side[i] = cube[side][i];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[side][(j) * 3 + (2 - i)] = temp_side[i * 3 + j];
		}
	}

	if (side == 0) {
		char temp[3] = { cube[1][6] ,cube[1][7] ,cube[1][8] };
		cube[1][6] = cube[4][8];
		cube[1][7] = cube[4][5];
		cube[1][8] = cube[4][2];

		cube[4][2] = cube[3][0];
		cube[4][5] = cube[3][1];
		cube[4][8] = cube[3][2];

		cube[3][0] = cube[2][6];
		cube[3][1] = cube[2][3];
		cube[3][2] = cube[2][0];

		cube[2][0] = temp[0];
		cube[2][3] = temp[1];
		cube[2][6] = temp[2];
	}
	else if (side == 1) {
		char temp[3] = { cube[0][0] ,cube[0][1] ,cube[0][2] };
		cube[0][0] = cube[2][0];
		cube[0][1] = cube[2][1];
		cube[0][2] = cube[2][2];

		cube[2][0] = cube[5][0];
		cube[2][1] = cube[5][1];
		cube[2][2] = cube[5][2];

		cube[5][0] = cube[4][0];
		cube[5][1] = cube[4][1];
		cube[5][2] = cube[4][2];

		cube[4][0] = temp[0];
		cube[4][1] = temp[1];
		cube[4][2] = temp[2];
	}
	else if (side == 2) {
		char temp[3] = { cube[0][2] ,cube[0][5] ,cube[0][8] };
		cube[0][2] = cube[3][2];
		cube[0][5] = cube[3][5];
		cube[0][8] = cube[3][8];

		cube[3][2] = cube[5][6];
		cube[3][5] = cube[5][3];
		cube[3][8] = cube[5][0];

		cube[5][0] = cube[1][8];
		cube[5][3] = cube[1][5];
		cube[5][6] = cube[1][2];

		cube[1][2] = temp[0];
		cube[1][5] = temp[1];
		cube[1][8] = temp[2];
	}
	else if (side == 3) {
		char temp[3] = { cube[0][6] ,cube[0][7] ,cube[0][8] };
		cube[0][6] = cube[4][6];
		cube[0][7] = cube[4][7];
		cube[0][8] = cube[4][8];

		cube[4][6] = cube[5][6];
		cube[4][7] = cube[5][7];
		cube[4][8] = cube[5][8];

		cube[5][6] = cube[2][6];
		cube[5][7] = cube[2][7];
		cube[5][8] = cube[2][8];

		cube[2][6] = temp[0];
		cube[2][7] = temp[1];
		cube[2][8] = temp[2];
	}
	else if (side == 4) {
		char temp[3] = { cube[0][0] ,cube[0][3] ,cube[0][6] };
		cube[0][0] = cube[1][0];
		cube[0][3] = cube[1][3];
		cube[0][6] = cube[1][6];

		cube[1][0] = cube[5][8];
		cube[1][3] = cube[5][5];
		cube[1][6] = cube[5][2];

		cube[5][8] = cube[3][0];
		cube[5][5] = cube[3][3];
		cube[5][2] = cube[3][6];

		cube[3][0] = temp[0];
		cube[3][3] = temp[1];
		cube[3][6] = temp[2];
	}
	else if (side == 5) {
		char temp[3] = { cube[1][0] ,cube[1][1] ,cube[1][2] };
		cube[1][0] = cube[2][2];
		cube[1][1] = cube[2][5];
		cube[1][2] = cube[2][8];

		cube[2][2] = cube[3][8];
		cube[2][5] = cube[3][7];
		cube[2][8] = cube[3][6];

		cube[3][6] = cube[4][0];
		cube[3][7] = cube[4][3];
		cube[3][8] = cube[4][6];

		cube[4][0] = temp[2];
		cube[4][3] = temp[1];
		cube[4][6] = temp[0];
	}
	
	/*
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << temp_side[(i) * 3 + j] << ' ';
		}cout << endl;
	}cout << endl;

	for (int s = 0; s < 6; s++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[s][(i) * 3 + j] << ' ';
			}cout << endl;
		}cout << endl;
	}
	*/
	return;
}

void Rw(int side) {
	char temp_side[9];
	for (int i = 0; i < 9; i++) {
		temp_side[i] = cube[side][i];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[side][(2 - j) * 3 + i] = temp_side[i * 3 + j];
		}
	}

	if (side == 0) {
		char temp[3] = { cube[1][6] ,cube[1][7] ,cube[1][8] };
		cube[1][6] = cube[2][0];
		cube[1][7] = cube[2][3];
		cube[1][8] = cube[2][6];

		cube[2][0] = cube[3][2];
		cube[2][3] = cube[3][1];
		cube[2][6] = cube[3][0];

		cube[3][0] = cube[4][2];
		cube[3][1] = cube[4][5];
		cube[3][2] = cube[4][8];

		cube[4][2] = temp[2];
		cube[4][5] = temp[1];
		cube[4][8] = temp[0];
	}
	else if (side == 1) {
		char temp[3] = { cube[0][0] ,cube[0][1] ,cube[0][2] };
		cube[0][0] = cube[4][0];
		cube[0][1] = cube[4][1];
		cube[0][2] = cube[4][2];

		cube[4][0] = cube[5][0];
		cube[4][1] = cube[5][1];
		cube[4][2] = cube[5][2];

		cube[5][0] = cube[2][0];
		cube[5][1] = cube[2][1];
		cube[5][2] = cube[2][2];

		cube[2][0] = temp[0];
		cube[2][1] = temp[1];
		cube[2][2] = temp[2];
	}
	else if (side == 2) {
		char temp[3] = { cube[0][2] ,cube[0][5] ,cube[0][8] };
		cube[0][2] = cube[1][2];
		cube[0][5] = cube[1][5];
		cube[0][8] = cube[1][8];

		cube[1][2] = cube[5][6];
		cube[1][5] = cube[5][3];
		cube[1][8] = cube[5][0];

		cube[5][0] = cube[3][8];
		cube[5][3] = cube[3][5];
		cube[5][6] = cube[3][2];

		cube[3][2] = temp[0];
		cube[3][5] = temp[1];
		cube[3][8] = temp[2];
	}
	else if (side == 3) {
		char temp[3] = { cube[0][6] ,cube[0][7] ,cube[0][8] };
		cube[0][6] = cube[2][6];
		cube[0][7] = cube[2][7];
		cube[0][8] = cube[2][8];

		cube[2][6] = cube[5][6];
		cube[2][7] = cube[5][7];
		cube[2][8] = cube[5][8];

		cube[5][6] = cube[4][6];
		cube[5][7] = cube[4][7];
		cube[5][8] = cube[4][8];

		cube[4][6] = temp[0];
		cube[4][7] = temp[1];
		cube[4][8] = temp[2];
	}
	else if (side == 4) {
		char temp[3] = { cube[0][0] ,cube[0][3] ,cube[0][6] };
		cube[0][0] = cube[3][0];
		cube[0][3] = cube[3][3];
		cube[0][6] = cube[3][6];

		cube[3][0] = cube[5][8];
		cube[3][3] = cube[5][5];
		cube[3][6] = cube[5][2];

		cube[5][8] = cube[1][0];
		cube[5][5] = cube[1][3];
		cube[5][2] = cube[1][6];

		cube[1][0] = temp[0];
		cube[1][3] = temp[1];
		cube[1][6] = temp[2];
	}
	else if (side == 5) {
		char temp[3] = { cube[1][0] ,cube[1][1] ,cube[1][2] };
		cube[1][0] = cube[4][6];
		cube[1][1] = cube[4][3];
		cube[1][2] = cube[4][0];

		cube[4][0] = cube[3][6];
		cube[4][3] = cube[3][7];
		cube[4][6] = cube[3][8];

		cube[3][6] = cube[2][8];
		cube[3][7] = cube[2][5];
		cube[3][8] = cube[2][2];

		cube[2][2] = temp[0];
		cube[2][5] = temp[1];
		cube[2][8] = temp[2];
	}

	/*
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << temp_side[(i) * 3 + j] << ' ';
		}cout << endl;
	}cout << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[side][(i) * 3 + j] << ' ';
		}cout << endl;
	}
	*/
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	//Cw(0);
	//Cw(5);
	//Rw(0);

	cin >> T;
	fflush(stdin);
	while (T--) {
		Init();
		cin >> n;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;

			int side, dir;
			//F:0 U:1 R:2 D:3 L:4 B:5
			if (s[0] == 'F') {
				side = 0;
			}
			else if (s[0] == 'U') {
				side = 1;
			}
			else if (s[0] == 'R') {
				side = 2;
			}
			else if (s[0] == 'D') {
				side = 3;
			}
			else if (s[0] == 'L') {
				side = 4;
			}
			else if (s[0] == 'B') {
				side = 5;
			}

			if (s[1] == '+') {
				Cw(side);
				//dir = 1;
			}
			else {
				Rw(side);
				//dir = -1;
			}

		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[1][i * 3 + j];
			}cout << '\n';
		}
	}
	
	//system("pause");
	return 0;
}
