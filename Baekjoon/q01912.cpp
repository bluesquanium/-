#include<cstdio>
int cur,N,ans=-1000,temp;
int main(){
	scanf("%d",&N);
	while(N--){
		scanf("%d",&temp);
		cur+=temp;
		ans=ans>cur?ans:cur;
		if(cur<0)cur=0;
	}
	printf("%d",ans);
}
