#include <cstdio>
int main() {
	int n, a, c=0, prime[1001] = {0};
	for(int i = 2; i < 1001; i++) prime[i] = 1;
	for(int i = 2; i <= 31; i++) {
		if(prime[i] == 1) {
			for(int j = i*2; j < 1001; j+=i) prime[j] = 0;
		}
	}
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		if(prime[a] == 1) c++;
	}
	printf("%d",c);
}
