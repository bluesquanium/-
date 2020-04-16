#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, M, ans;
vector<int> m;

vector< vector<ll> > factors;
void updateFactors(int n) {
	factors.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			factors[j].push_back(i);
		}
	}
}
