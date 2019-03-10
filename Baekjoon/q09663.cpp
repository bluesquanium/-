#include <iostream>
using namespace std;

int N, q[15], ans;

void Dfs(int count) {
	if(count<N) {
		int p[N] = {0,};
		for(int i = 0; i < count; i++) {
			if(q[i]-(count-i) >= 0) {
				p[q[i]-(count-i)] = 1;
			}
			if(q[i]+(count-i) < N) {
				p[q[i]+(count-i)] = 1;	
			}
			p[q[i]] = 1;
		} 
		
		for(int i = 0; i < N; i++) {
			if(p[i]==0) {
				q[count] = i;
				Dfs(count+1);
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
