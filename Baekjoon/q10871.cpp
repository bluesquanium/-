#include <stdio.h>

int N, X, temp;

int main(void) {
	scanf("%d %d",&N, &X);
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		if( temp < X) {
			printf("%d ", temp);
		}
	}

	return 0;
}
