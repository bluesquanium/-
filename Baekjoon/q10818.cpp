#include <stdio.h>

int N, mini, maxi, temp;

int main(void) {
	mini = 1000000;
	maxi = -1000000;

	scanf("%d",&N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		if (temp < mini) {
			mini = temp;
		}
		if (temp > maxi) {
			maxi = temp;
		}
	}
	
	printf("%d %d\n", mini, maxi);
	return 0;
}
