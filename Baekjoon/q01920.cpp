#include <cstdio>
#include <algorithm>
using namespace std;

int a[100001];

int BinarySearch(int * a, int target, int prev, int end) {
	//iterative함수 버전 
	int mid, result = 0;
	while(prev < end) {
		mid = (prev+end)/2;
		
		if(a[mid] == target) {
			result = 1;
			break;
		}
		else if(a[mid] > target) {
			end = mid;
		}
		else {
			prev = mid + 1;
		}
	}
	return result;
}

int main(void) {
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	scanf("%d",&m);
	for(int i = 0; i < m; i++) {
		int num, check = 0;
		scanf("%d",&num);
		check = BinarySearch(a, num, 0, n);
		printf("%d\n", check );
	}
	
	return 0;
}
