#include <stdio.h>

int A;
char B;

int main(void) {
	scanf("%d", &A);
	A /= 10;
	switch (A) {
	case 9:
	case 10:
		B = 'A';
		break;
	case 8:
		B = 'B';
		break;
	case 7:
		B = 'C';
		break;
	case 6:
		B = 'D';
		break;
	default:
		B = 'F';
		break;
	}

	printf("%c", B);

	return 0;
}
