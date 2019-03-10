#include <iostream>
using namespace std;

int N, ans;
int col[15], d1[31],d2[31];


void Dfs(int count) {
	if(count<N) {
		for(int i = 0; i < N; i++) {
			if(col[i]==0&&d1[count+i]==0&&d2[N+count-i]==0) {
				col[i]=1; d1[count+i]=1; d2[N+count-i]=1;
				Dfs(count+1);
				col[i]=0; d1[count+i]=0; d2[N+count-i]=0;
			}
		}
		
		return;
	}
	
	ans++;
	return;
}

int main(void) {
	cin >> N;
	Dfs(0);	
	cout << ans;
	return 0;
}
