#include <iostream>
using namespace std;
int main() {
	int n,m,r;
	cin>>n>>m;
	r=n*m;
	while(n*m)n>m?n%=m:m%=n;
	cout<<n+m<<'\n'<<r/(n+m);
}
