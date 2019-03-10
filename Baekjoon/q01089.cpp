#include <iostream>
#include <vector>
using namespace std;

int z[5][30] = { {1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				 {1,0,1,0,0,1,0,0,1,0,0,1,1,0,1,1,0,0,1,0,0,0,0,1,1,0,1,1,0,1},
				 {1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
				 {1,0,1,0,0,1,1,0,0,0,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1,0,1,0,0,1},
				 {1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1}
				};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long n, sum = 0;
	vector< vector<int> > possible_nums;
	string display[5];
	cin >> n;
	for(int i = 0; i < 5; i++)
		cin >> display[i];
	
	for(int i = 0; i < 4*n-1; i+=4) {
		vector<int> temp;
		int possible[10] = {0}; // ¿÷¿∏∏È 0, æ¯¿∏∏È -1 
		for(int j = 0; j < 10; j++) {
			for(int k = 0; k < 5; k++) {
				if( display[k][i+0] == '#' ) {
					if( z[k][j*3+0] != 1 ) { // ∂Ø! 
						possible[j] = -1;
						break;
					}
				}
				if( display[k][i+1] == '#' ) {
					if( z[k][j*3+1] != 1 ) { // ∂Ø! 
						possible[j] = -1;
						break;
					}
				}
				if( display[k][i+2] == '#' ) {
					if( z[k][j*3+2] != 1 ) { // ∂Ø! 
						possible[j] = -1;
						break;
					}
				}
			}
		}
		for(int j = 0; j < 10; j++)
			if( possible[j] == 0 )
				temp.push_back(j);
		
		if(temp.empty()) { //≥°≥ø 
			cout << -1; 
			return 0;
		}
		possible_nums.push_back(temp);
	}

	for(int i = 0; i < n; i++) {
		int temp = 1;
		sum *= 10;
		for(int j = 0; j < n; j++)
			if(i != j) temp *= possible_nums[j].size();
		for(int j = 0; j < possible_nums[i].size(); j++)
			sum += (possible_nums[i])[j] *temp;
	}
	int count = 1;
	for(int i = 0; i < n; i++)
		count *= possible_nums[i].size();
	
	cout << fixed; cout.precision(7);
	cout << (double)sum/count << endl;

	return 0;
}
