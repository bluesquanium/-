#include <iostream>
#include <algorithm>
using namespace std;

int n, l;
int map[100][100];

int Answer() {
	int total = 0;
	for(int i = 0; i < n; i++) {
		bool check1 = true, check2 = true;
		int cur_height1 = map[i][0]; // horizontal
		int cur_height2 = map[0][i]; // vertical
		int count1 = 0, count2 = 0;
		for(int j = 0; j < n; j++) {
			//horizontal
			if( cur_height1 == map[i][j] )// ³ôÀÌ °°Àº °æ¿ì 
				count1++;
			else if( cur_height1 < map[i][j] && (count1 < l) )
				check1 = false;
			else if( abs(cur_height1 - map[i][j]) > 1 )
				check1 = false;
			else if( count1 < 0 )
				check1 = false;
			else {
				count1 = cur_height1 < map[i][j] ? 1 : -l+1;
				cur_height1 = map[i][j];
			}
			//vertical
			if( cur_height2 == map[j][i] )
				count2++;
			else if( cur_height2 < map[j][i] && (count2 < l || abs(cur_height2 - map[j][i]) > 1) )
				check2 = false;
			else if( abs(cur_height2 - map[j][i]) > 1 )
				check2 = false;
			else if( count2 < 0 )
				check2 = false;
			else {
				count2 = cur_height2 < map[j][i] ? 1 : -l+1;
				cur_height2 = map[j][i];
			}
			
			if(check1==false&&check2==false) break;
		}
		if(check1 == true && count1 >= 0) total++;
		if(check2 == true && count2 >= 0) total++;
	}
	
	return total;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> n >> l;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	cout << Answer();
	
	return 0;
} 
