#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, K, ans, temp;
vector<int> coins;
vector<int> after;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	after.resize(K+1);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp <= 10000) {
			coins.push_back(temp);
		}
	}
	N = coins.size();
	sort(coins.begin(), coins.end());

	after[0] = 1;
	for (int n = 0; n < N; n++) {
		for (int mod = 0; mod < coins[n]; mod++) {
			int cur = coins[n] + mod;
			while (cur <= K) {
				after[cur] += after[cur - coins[n]];

				cur += coins[n];
			}
		}
	}

	printf("%d", after[K]);

	return 0;
}
