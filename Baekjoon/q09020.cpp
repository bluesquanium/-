#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

#define MAX 10000
#define INF 999999999
ll T, N, ans[3];

vector<int> prime;
int mem[MAX + 1];
void findPrime() {
	for (int i = 2; i <= MAX; i++) {
		if (mem[i] == 0) {
			prime.push_back(i);
			int j = i * 2;
			while (j <= MAX) {
				mem[j] = -1;

				j += i;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	findPrime();
	cin >> T;
	for (ll t = 0; t < T; t++) {
		ans[0] = ans[1] = 0;
		ans[2] = INF;

		cin >> N;
		int idxMax = -1;
		for (int i = 0; i < prime.size(); i++) {
			if (prime[i] > N) {
				idxMax = i;
				break;
			}
		}
		if (idxMax == -1) {
			idxMax = prime.size() - 1;
		}

		for (int i = 0; i <= idxMax; i++) {
			for (int j = i; j <= idxMax; j++) {
				if (prime[i] + prime[j] == N) {
					if (ans[2] > prime[j] - prime[i]) {
						ans[0] = prime[i];
						ans[1] = prime[j];
						ans[2] = prime[j] - prime[i];
					}
				}
			}
		}
		
		cout << ans[0] << ' ' << ans[1] << '\n';
	}

	return 0;
}
