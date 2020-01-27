#include <stdio.h>

int N, ans;

int main(void) {
	scanf("%d", &N);
	if (N % 4 == 0 && (N % 100 != 0 || N % 400 == 0)) {
		ans = 1;
	}

	printf("%d", ans);

	return 0;
}
