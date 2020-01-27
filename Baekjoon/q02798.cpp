#include <stdio.h>

int N, M, ans;
int m[100];

int main(void) {
	scanf("%d %d",&N, &M);
	for(int i = 0; i < N; i++) {
		scanf("%d", &m[i]);
	}
	
	for(int i = 0; i < N-2; i++) {
		for(int j = i+1; j < N-1; j++) {
			for(int k = j+1; k < N; k++) {
				int sum = m[i] + m[j]+ m[k];
				if(sum <= M && sum > ans) {
					ans = sum;
				}
			}
		}
	}
	
	printf("%d", ans);
	return 0;
}
