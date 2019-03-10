#include <iostream>
#include <vector>
using namespace std;

vector<string> MakeWord(string s1) {
	vector<string> word1;
	string temp;
	for(int i = 0; i < s1.length(); i++) {
		if(s1[i] == ' ') {
			if(!temp.empty()) {
				word1.push_back(temp);
				temp.clear();
			}
		}
		else if('A' <= s1[i] && s1[i] <= 'Z') { //대문자는 그냥 저장
			temp += s1[i]; 
		}
		else if('a' <= s1[i] && s1[i] <= 'z') { //대문자 만들어서 저장 
			temp += (s1[i]-32);
		}
		else if('0' <= s1[i] && s1[i] <= '9') { //숫자 저장 
			temp += s1[i];
		}
		else if(s1[i] == '(' || s1[i] == '[' || s1[i] == '{') {
			if(!temp.empty()) {
				word1.push_back(temp);
				temp.clear();
			}
			word1.push_back("(");
		}
		else if(s1[i] == ')' || s1[i] == ']' || s1[i] == '}') {
			if(!temp.empty()) {
				word1.push_back(temp);
				temp.clear();
			}
			word1.push_back(")");
		}
		else if(s1[i] == ',' || s1[i] == ';') {
			if(!temp.empty()) {
				word1.push_back(temp);
				temp.clear();
			}
			word1.push_back(",");
		}
		else if(s1[i] == '.' || s1[i] == ':') {
			if(!temp.empty()) {
				word1.push_back(temp);
				temp.clear();
			}
			temp = s1[i];
			word1.push_back(temp);
			temp.clear();
		}
	}
	if(!temp.empty()) {
		word1.push_back(temp);
		temp.clear();
	}
	
	return word1;
}

int main(void) {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	
	int k;
	cin >> k;
	fflush(stdin);
	for(int l = 1; l <= k; l++) {
		//string s1, s2;
		char temp1[1001], temp2[1001];
		string s1, s2;
		vector<string> word1, word2;
		bool is_equal = true;
		cin.getline(temp1,1001);
		cin.getline(temp2,1001);
		s1 = temp1; s2 = temp2;
		
		word1 = MakeWord(s1);
		word2 = MakeWord(s2);
		
		if(word1.size() != word2.size()) {
			is_equal = false;
		}
		else {
			for(int i = 0; i < word1.size(); i++) {
				if(word1[i] != word2[i]) {
					is_equal = false;
					break;
				}
			}
		}
		/*
		for(int i = 0; i < word1.size(); i++) {
			cout << word1[i] << ' ';
		}*/
		
		if(l!=1) {
			cout << "\n\n";
		}
		
		cout << "Data Set " << l << ": ";
		if(is_equal) {
			cout << "equal";
		}
		else {
			cout << "not equal";
		}
	}
	
	return 0;
}
