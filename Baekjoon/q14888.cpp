#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX	11

int n, result_max = -1000000001, result_min = 1000000001;
vector<int> oper;
int is_used[MAX];
int nums[MAX];

void Dfs(int count) {
	int num_oper = oper.size();
	if(count != num_oper) {
		for(int i = 0; i < num_oper; i++) {
			if(is_used[i] == -1) {
				is_used[i] = count;
				Dfs(count+1);
				is_used[i] = -1;
			}
		}
		
		return;
	}
	/*
	for(int i = 0; i < num_oper; i++) {
		printf("%d ", is_used[i]);
	}
	putchar('\n');
	*/
	
	int sum = nums[0];
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < num_oper; j++) {
			if(is_used[j] == i-1) {
				if(oper[j] == 0) sum += nums[i];
				else if(oper[j] == 1) sum -= nums[i];
				else if(oper[j] == 2) sum *= nums[i];
				else sum /= nums[i];
				
				break;
			}
		}
	}
	result_max = max(result_max, sum);
	result_min = min(result_min, sum);
}

int main(void) {
	memset(is_used, -1, sizeof(is_used));
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	for(int i = 0; i < 4; i++) {
		int temp;
		scanf("%d", &temp);
		for(int j = 0; j < temp; j++) {
			oper.push_back(i);
		}
	}
	/*
	for(int i = 0; i < oper.size(); i++) {
		printf("%d ",oper[i]);
	}
	*/
	
	Dfs(0);
	printf("%d\n%d",result_max, result_min);

	return 0;
}
