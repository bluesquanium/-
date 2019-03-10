#include<cstdio>
int main(){
long long n,k,i,a=1;
scanf("%lld%lld",&n,&k);
for(i=0;i<k;i++)a*=n-i;
for(i=2;i<=k;i++)a/=i;
printf("%lld",a);
}
