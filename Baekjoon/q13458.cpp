#include <iostream>
using namespace std;

int N, B, C, m[1000000];
long long ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> m[i];
	}
	cin >> B >> C;
	for(int i = 0; i  <N; i++) {
		if(m[i] <= B) ans += 1;
		else ans += 1 + (m[i]-B+C-1)/C;
	}
	cout << ans;

	return 0;
}
