#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX	15

int n;
int result_max = 0;
int schedule[MAX][2];

void MaxEarn(int dayfrom, int result) {
	if( dayfrom == n) {
		result_max = max(result_max, result);
		return;
	}
	else if( dayfrom > n ) {
		return;
	}
	
	for(int i = dayfrom; i < n; i++) {
		MaxEarn(i+schedule[i][0], result+schedule[i][1]);
	}
	result_max = max(result_max, result);
	return;
}

int main(void) {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &schedule[i][0], &schedule[i][1]);
	}
	
	MaxEarn(0, 0);
	printf("%d", result_max);

	return 0;
} 
