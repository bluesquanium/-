#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int point[n][2];
	for(int i = 0; i < n; i++) {
		cin >> point[i][0] >> point[i][1];
	}
	
	int max_area = 0;
	for(int i = 0; i < n-1; i++) {
		int min_height = point[i][1];
		bool check_min_x = false;
		int min_x = -1;
		for(int j = i+1; j < n; j++) {
			min_height = min(min_height, point[j][1]);
			if(check_min_x == false && min_height != point[i][1]) {
				check_min_x = true;
				min_x = point[j][0];
			}
			int area;
			if(min_x == -1) {
				area = (point[j][0]-point[i][0])*(point[i][1]);
			}
			else {
				area = (point[j][0]-point[i][0])*(point[i][1]) - (point[i][1]-min_height)*(point[j][0]-min_x);
			}
			
			max_area = max(area, max_area);
		}
	}
	
	for(int i = n-1; i > 0; i--) {
		int min_height = point[i][1];
		bool check_max_x = false;
		int max_x = -1;
		for(int j = i-1; j >= 0; j--) {
			min_height = min(min_height, point[j][1]);
			if(check_max_x == false && min_height != point[i][1]) {
				check_max_x = true;
				max_x = max(max_x, point[j][0]);
			}
			int area;
			if(max_x == -1) {
				area = (point[i][0]-point[j][0])*(point[i][1]);
			}
			else {
				area = (point[i][0]-point[j][0])*(point[i][1]) - (point[i][1]-min_height)*(max_x-point[j][0]);
			}
			
			max_area = max(area, max_area);
		}
	}
	
	
	cout << max_area;
	
	return 0;
}
