#include <iostream>
using namespace std;
int N, M;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	cout << M*(N-1)+M-1;
	return 0;
}
