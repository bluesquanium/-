#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, b;
vector<int> B;

int main(void) {
	cin >> N >> M >> K;
	
	for(int i = 0; i < N; i++) {
		cin >> b;
		B.push_back(b);
	}
	
	return 0;
}
