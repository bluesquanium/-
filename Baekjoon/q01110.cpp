#include <cstdio>
int main(void) {
	int n, a, c=1;
	scanf("%d",&n);
	a=n;
	while(1) {
		a = (a%10)*10 + (a%10+a/10)%10;
		if(a==n)break;
		c++;
	}
	printf("%d",c);
}
