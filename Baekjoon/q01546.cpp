#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, maxi;
double ans;
vector<int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i];
		ans += m[i];
		if (maxi < m[i]) {
			maxi = m[i];
		}
	}

	ans = ans * 100 / maxi;
	printf("%lf", ans / N);

	return 0;
}
