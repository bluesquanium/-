#include <stdio.h>

int N;

int main(void) {
	scanf("%d",&N);
	if (N < 100) {
		printf("%d", N);
	}
	else {
		int cnt =  99;
		for(int i = 111; i <= N && i < 1000; i++) {
			int num = i;
			int a = num%10, b = (num/10)%10, c = (num/100)%10;
			if(a - b == b - c) {
				cnt++;
			}
		}
		printf("%d", cnt);
	}
	

	return 0;
}
