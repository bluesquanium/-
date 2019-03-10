#include <iostream>
using namespace std;

int main(void) {
	int scoreboard1[9] = {0,};
	int scoreboard2[9] = {0,};
	int score1 = 0, score2 = 0;
	bool check = false; // Áö´ø °æ¿ì°¡ ÀÖ´ÂÁö Ã¼Å© 
	for(int i = 0; i < 9; i++) {
		cin >> scoreboard1[i];
	}
	for(int i = 0; i < 9; i++) {
		cin >> scoreboard2[i];
	}
	
	for(int i = 0; i < 9; i++) {
		score1 += scoreboard1[i];
		if(score1 > score2) {
			check = true;
			break;
		}
		score2 += scoreboard2[i];
	}
	
	if(check)
		cout << "Yes";
	else
		cout << "No";
	
	return 0;
}
