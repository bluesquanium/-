#include <stdio.h>

int m[3];

void swap(int * a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	scanf("%d %d %d", &m[0], &m[1], &m[2]);
	for (int i = 0; i < 2; i++) {
		if (m[0] < m[1]) {
			swap(&m[0], &m[1]);
		}
		if (m[1] < m[2]) {
			swap(&m[2], &m[1]);
		}
	}
	
	printf("%d", m[1]);

	return 0;
}
