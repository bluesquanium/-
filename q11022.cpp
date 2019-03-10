#include <cstdio>
using namespace std;

int main(void) {
	int t;
	scanf("%d",&t);
    for(int i = 0; i < t; i++) {
	    long long a, b;
	    scanf("%d %d",&a,&b);
	    printf("Case #%d: %d + %d = %d\n",i+1,a,b,a+b);
    }
	
	return 0;
}
