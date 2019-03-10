#include <iostream>
#include <algorithm>
using namespace std;

int Find(int x, int * parent) {
	if(parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = Find(parent[x], parent);
	}
}

void Union(int x, int y, int * parent) {
	x = Find(x, parent);
	y = Find(y, parent);
	
	if(x!=y) {
		if(parent[x] < parent[y]) {
			swap(x,y);
		}
		parent[y] = x;
	}
}

int main(void) {
	//Input
	int n, m;
	cin >> n >> m;
	int parent[n+1]; // 0번은 더미 
	for(int i = 1; i < n+1; i++) { // 부모 정보 초기화 
		parent[i] = i;
	}
	for(int i = 0; i < m; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		Union(temp1, temp2, parent);
	}
	
	//Check
	int count = 0;
	int check[n+1] = {0,};
	for(int i = 1; i < n+1; i++) {
		if( check[Find(parent[i], parent)] != 1 ) {
			check[Find(parent[i], parent)] = 1;
			count ++;
		}
	}
	cout << count;
	
	return 0;
}
