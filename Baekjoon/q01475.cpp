#include <iostream>
using namespace std;

int num[10], ans;

int main(void) {
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		num[s[i]-'0']++;
	}
	num[6] = (num[6]+num[9]+1)/2;
	for(int i = 0; i < 9; i++) {
		ans = max(ans,num[i]);
	}
	cout << ans;
	return 0;
}
