#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int k, result = 0;
	string wheel[4];
	int cur[4] = {0,}; //0: 위, 2:오른쪽, 4: 아래, 6:왼쪽 
	for(int i = 0; i < 4; i++) {
		cin >> wheel[i];
	}
	cin >> k;
	for(int j = 0; j < k; j++) {
		int move[4] = {0,0,0,0}; // 1: 시계, -1: 반시계 
		int command[2];
		cin >> command[0] >> command[1];
		command[0]--; // 번호 0번부터 시작하므로 
		move[command[0]] = command[1];
		
		for(int i = command[0]; i < 3; i++) {
			if(wheel[i][(cur[i]+2)%8]!=wheel[i+1][(cur[i+1]+6)%8]) move[i+1] = -1*move[i];
		}
		for(int i = command[0]; i > 0; i--) {
			if(wheel[i][(cur[i]+6)%8]!=wheel[i-1][(cur[i-1]+2)%8]) move[i-1] = -1*move[i];
		}
		
		for(int i = 0; i < 4; i++) {
			cur[i] = (8-1*move[i] + cur[i])%8;
		}
	}
	
	for(int i = 3; i >= 0; i--) {
		result *= 2;
		result += wheel[i][cur[i]]-'0';
	}
	
	cout << result;
	
	return 0;
}
