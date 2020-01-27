#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int N, temp;
priority_queue<int, vector<int>, less<int> > pq;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		cin >> temp;
		if(temp == 0) {
			if(pq.size() == 0) {
				printf("0\n");
			} else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		} else {
			pq.push(temp);
		}
	}
	
	return 0;
}
