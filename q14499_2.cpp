/*
 * c[4][6]을 선언해서 한 게 획기적이고 코드 단축에 큰 영향을 줌. 
 */
#include<cstdio>
#define F(X) for(i=0;i<X;i++)
int q[4]={1,-1,0,0},r[4]={0,0,-1,1},c[4][6]={{2,0,5,3,4,1},{1,5,0,3,4,2},{4,1,2,0,5,3},{3,1,2,5,0,4}},s[6],t[6],n,m,y,x,k,z,i;int main(){scanf("%d%d%d%d%d",&n,&m,&y,&x,&k);int a[n][m];F(n*m)scanf("%d",*a+i);while(k--){scanf("%d",&z);z--;int e=y+r[z],d=x+q[z];if(0<=e&&e<n&&0<=d&&d<m){y=e;x=d;F(6)t[i]=s[c[z][i]];F(6)s[i]=t[i];if(a[e][d]==0)a[e][d]=s[5];else {s[5]=a[e][d];a[e][d]=0;}printf("%d\n",s[0]);}}}
