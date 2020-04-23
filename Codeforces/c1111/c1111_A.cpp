#include <iostream>
using namespace std;

int main(void) {
	string s, t;
	cin >> s;
	cin >> t;
	
	if(s.size() != t.size()) {
		cout << "No";
		return 0;
	}
	
	for(int i = 0; i < s.size(); i++) {
		if(s[i]==t[i]){
			continue;
		}
		else if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
			if(t[i]=='a' || t[i]=='e' || t[i]=='i' || t[i]=='o' || t[i]=='u') {
				continue;
			}
			else {
				cout << "No";
				return 0;
			}
		}
		else { // consonant
			if(t[i]=='a' || t[i]=='e' || t[i]=='i' || t[i]=='o' || t[i]=='u') {
				cout << "No";
				return 0;
			}
		}
	}
	
	cout << "Yes";
	return 0;
}
