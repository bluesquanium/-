#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string temp;
	int count = 0;
	while( cin >> temp ) {
		if(temp == "<br>") {
			cout << '\n';
			count = 0;
		}
		else if(temp == "<hr>") {
			if(count != 0) {
				cout << '\n';
			}
			cout << "--------------------------------------------------------------------------------\n";
			count = 0;
		}
		else {
			if(count + 1 + temp.length() <= 80) {
				if(count!=0) {
					cout << " ";
					count += 1;
				}
				cout << temp;
				count += temp.length();
			}
			else {
				cout << '\n' << temp;
				count = temp.length();
			}
		}
	}
	cout << '\n';
	
	return 0;
}
