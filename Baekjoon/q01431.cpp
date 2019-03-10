#include <iostream>
#include <algorithm>
using namespace std;

bool CompareStep1(string a, string b) {
	return a.length() < b.length();
}

bool CompareStep2(string a, string b) {
	int num_a = 0, num_b = 0;
	for(int i = 0; i < a.length(); i++) {
		if( '0' <= a[i] && a[i] <= '9' ) {
			num_a += a[i]-'0';
		}
	}
	for(int i = 0; i < b.length(); i++) {
		if( '0' <= b[i] && b[i] <= '9' ) {
			num_b += b[i]-'0';
		}
	}
	return num_a < num_b;
}

bool CompareStep3(string a, string b) {
	return a.compare(b)==-1?true:false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	string serial[n];
	for(int i = 0; i < n; i++) {
		cin >> serial[i];
	}
	sort(serial, serial+n, CompareStep1);
	sort(serial, serial+n, CompareStep2);
	sort(serial, serial+n, CompareStep3);
	
	for(int i = 0; i < n; i++) {
		cout << serial[i] << '\n';
	}

	return 0;
}
