// 숫자가 범위를 넘어가는 경우? 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool CompareString(string a, string b) {
	if(a.length() != b.length()) {
		return a.length() < b.length();
	}
	else {
		return a < b;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	vector<string> result;
	string temp;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		for(int j = 0; j < temp.size(); j++) {
			string num = "";
			while( j < temp.size() && '0' <= temp[j] && temp[j] <= '9' ) {
				if(num.length()==1 && num[0] == '0') {
					if(temp[j] != '0') {
						num[0] = temp[j];
					}
				}
				else {
					num += temp[j];
				}
				j++;
			}
			if( !num.empty() ) {
				result.push_back(num);
			}
		}
	}
	sort(result.begin(), result.end(), CompareString);
	
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	
	return 0;
}
