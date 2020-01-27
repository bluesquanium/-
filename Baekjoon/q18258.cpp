#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int N, n;
string s;
queue<int> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		cin >> s;
		if(s == "push") {
			cin >> n;
			q.push(n);	
		}
		else if (s == "pop") {
			if( q.empty() == true) {
				printf("%d\n", -1);
			}
			else {
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if (s == "front") {
			if( q.empty() == true) {
				printf("%d\n", -1);
			}
			else {
				printf("%d\n", q.front());
			}
		}
		else if (s == "back") {
			if( q.empty() == true) {
				printf("%d\n", -1);
			}
			else {
				printf("%d\n", q.back());
			}
		}
		else if (s == "size") {
			printf("%d\n", q.size());
		}
		else if (s == "empty") {
			printf("%d\n", q.empty());
		}
	}
	
	
	return 0;
}
