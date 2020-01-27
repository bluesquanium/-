#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll A, B, C, ans;
vector<int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	m.resize(10, 0);	
	cin >> A;
	cin >> B;
	cin >> C;

	ans = A * B * C;
	while (ans) {
		m[ans % 10]++;
		ans /= 10;
	}
	
	for (int i = 0; i < 10; i++) {
		cout << m[i] << '\n';
	}

	return 0;
}
