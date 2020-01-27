#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define M_PI       3.14159265358979323846

#define ll	long long
#define pii	pair<int,int>
using namespace std;

double R;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> R;

	cout << fixed;
	cout << R * R * M_PI << '\n';
	cout << R * R * (double)2;

	return 0;
}
