#include <cstdio>
int main(void) {
	int a[4], b[4]; // x1,y1,x2,y2
	scanf("%d%d%d%d",a,a+1,a+2,a+3);
	scanf("%d%d%d%d",b,b+1,b+2,b+3);
	
	if( b[0]>a[2] || b[2]<a[0] || b[1]>a[3] || b[3]<a[1] ) puts("NULL");
	else if( b[0]==a[2] || b[2]==a[0] || b[1]==a[3] || b[3]==a[1] ) {
		if( (b[0]==a[2] && b[1]==a[3]) || (b[1]==a[3] && b[2]==a[0]) ||
			(b[2]==a[0] && b[3]==a[1]) || (b[3]==a[1] && b[0]==a[2]) )
			puts("POINT");
		else puts("LINE");
	}
	else puts("FACE");

	return 0;
}
