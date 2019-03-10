#include <cstdio>
using namespace std;
int main(){
	int n,m,count = 0;
	scanf("%d%d",&n,&m);
	char tile[n][m];
	for(int i=0;i<n;i++){
		scanf("%s",tile[i]);
		for(int j=0; j<m;j++){
			if(tile[i][j]=='-'){
				count++;
				while(j<m&&tile[i][j]=='-')j++;
			}
		}
	}
	for(int j=0; j<m;j++){
		for(int i=0;i<n;i++){
			if(tile[i][j]=='|'){
				count++;
				while(i<n&&tile[i][j]=='|')i++;
			}
		}
	}
	printf("%d",count);
}
