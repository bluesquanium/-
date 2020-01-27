#include <stdio.h>

int H, M, ans;

int main(void) {
	scanf("%d %d", &H, &M);
	M -= 45;
	if (M < 0) {
		H--;
		M += 60;
	}

	if (H < 0) {
		H = 23;
	}
	

	printf("%d %d", H, M);

	return 0;
}
