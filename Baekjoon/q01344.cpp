#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define	MAX	18

bool isPrime[MAX+1] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0};

double A, B;
double dp[MAX+1][MAX+1][MAX+1];

double Solve(int r, int a, int b) {
	if(r==MAX) {
		return (isPrime[a] || isPrime[b])?1.0:0.0;
	}
	double& ret = dp[r][a][b];
	if(!isnan(ret)) return ret;
	ret = 0;
	ret += Solve(r+1, a,   b)  *(1-A)*(1-B);
	ret += Solve(r+1, a+1, b)  *(A  )*(1-B);
	ret += Solve(r+1, a,   b+1)*(1-A)*(B  );
	ret += Solve(r+1, a+1, b+1)*(A  )*(B  );
	return ret;
}

int main(void) {
	cin >> A >> B;
	A /= 100; B /= 100;
	memset(dp, -1, sizeof(dp));
	
	cout << fixed;
	cout.precision(30);
	cout << Solve(0,0,0);
	
	return 0;
}
