#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void) {
	int n;
	vector<int *> ratio;
	cin >> n;
	int result[n] = {0};
	//memset(result, -1, sizeof(int)*n);
	
	for(int i = 0; i < n-1; i++) {
		int* t = new int[4];
		cin >> t[0] >> t[1] >> t[2] >> t[3];
		ratio.push_back(t);
	}
	
	result[ratio[0][0]] = ratio[0][2];
	result[ratio[0][1]] = ratio[0][3];
	
	
	for(int i = 1; i < ratio.size(); i++) { // 레시피 1~n-2번 
		if( result[ratio[i][1]] != 0 ) {
			swap(ratio[i][0], ratio[i][1]);
			swap(ratio[i][2], ratio[i][3]);
		}
		
		int temp = ratio[i][2]; // 이미 비율 등록된 놈의 비율값 
		if( result[ratio[i][0]] != 0 ) {
			/*
			for(int l = 0; l < n; l++) {
				cout << result[l] << ' ';
			}
			cout << '\n'; 
			*/
		
			result[ratio[i][1]] = ratio[i][3] * result[ratio[i][0]]; // 새로운 놈 등록 
			for(int j = 0; j < n; j++) {
				if(j != ratio[i][1]) { // 새로 등록한 놈 이미 업데이트 했으므로 제외 
					result[j] *= temp;
				} 
			}
		}
		else { // ratio 길이 늘려줌 
			ratio.push_back(ratio[i]);
		}
	}
	
	int minimum = result[0];
	for(int i = 0; i < n; i++) {
		minimum = min(minimum, result[i]);
	}
	 
	for(int i = 2; i <= minimum; i++) {
		bool check = true;
		for(int j = 0; j < n; j++) {
			if( result[j]%i != 0 ) {
				check = false;
				break;
			}
		}
		if(check == true) {
			for(int j = 0; j < n; j++) {
				result[j] /= i;
			}
			minimum /= i; // minimum도 줄여줌 
			i = 1; // 다시 2부터 확인 
		}
	}
	
	for(int i = 0; i < n; i++) {
		cout << result[i] << ' ';
	}
	
	
	return 0;
}
