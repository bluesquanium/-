#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, B, A;
int m[200000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> B >> A;
	for (int i = 0; i < N; i++) {
		cin >> m[i];
	}

	int cur = 0, b = B, a = A;
	cur++; a--; // 0번째 무조건 a 소모
	while (cur < N) {
		if (m[cur] == 0) {
			if (a > 0) {
				a--;
			}
			else if (b > 0) {
				b--;
			}
			else {
				break;
			}
		}
		else { // m[cur] == 1
			if (a > 0 || b > 0) {
				if (a < A) {
					if (b > 0) {
						b--;
						a++;
					}
					else {
						a--;
					}
				}
				else {
					a--;
				}
			}
			else {
				break;
			}
		}
		cur++;
	}

	cout << cur;

	return 0;
}
