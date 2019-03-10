#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int k, result = 0;
	string wheel[4];
	int cur[4] = {0,}; //0: ��, 2:������, 4: �Ʒ�, 6:���� 
	for(int i = 0; i < 4; i++) {
		cin >> wheel[i];
	}
	cin >> k;
	for(int j = 0; j < k; j++) {
		int move[4] = {0,0,0,0}; // 1: �ð�, -1: �ݽð� 
		int command[2];
		cin >> command[0] >> command[1];
		command[0]--; // ��ȣ 0������ �����ϹǷ� 
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
