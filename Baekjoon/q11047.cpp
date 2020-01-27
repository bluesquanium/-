#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, ans, max_idx;
vector<int> v;

int main(void) {
	scanf("%d %d",&N, &K);
	v.resize(N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
		if (v[i] <=  K) {
			max_idx = i;
		}
	}
	
	int sum = 0;
	for(int i = max_idx; i >= 0; i--) {
		
		while (sum + v[i] <= K) {
			sum += v[i];
			ans++;
		}
		if (sum == K) {
			printf("%d", ans);
			break;
		}
	}
	
	return 0;
}
