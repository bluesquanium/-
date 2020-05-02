#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

#define MAX 45
int N, ans;
int mem[MAX + 1];

void findFibo() {
	mem[1] = mem[2] = 1;
	for (int i = 3; i <= MAX; i++) {
		mem[i] = mem[i - 1] + mem[i - 2];
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	findFibo();
	cin >> N;

	cout << mem[N];

	return 0;
}

