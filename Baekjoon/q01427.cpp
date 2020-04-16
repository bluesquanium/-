#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, M, ans;
vector<int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	while (N) {
		m.push_back(N % 10);
		N /= 10;
	}
	sort(m.rbegin(), m.rend());
	for (int i = 0; i < m.size(); i++){
		cout << m[i];
	}
	
	return 0;
}
