#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, M, ans;
vector<int> m;

int fact(int n) {
	if (n <= 1) {
		return 1;
	}

	return n * fact(n - 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;

	cout << fact(N);

	return 0;
}
