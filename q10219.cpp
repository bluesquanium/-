#include <iostream>
using namespace std;

int main(void) {
	int t;
	cin >> t;
	char grill[12][12];
	for(int i = 0; i < t; i++) {
		int h, w;
		cin >> h >> w;
		for(int j = 0; j < h; j++) {
			cin >>grill[j];
		}
		
		for(int j = h-1; j >= 0; j--) {
			cout << grill[j] << endl;
		}
	}
	
	return 0;
}
