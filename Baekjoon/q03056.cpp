#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
double ans;
double ** jimi;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	jimi = new double*[N];
	for (int i = 0; i < N; i++) {
		jimi[i] = new double[N];
		for (int j = 0; j < N; j++) {
			cin >> jimi[i][j];
			jimi[i][j] /= 100;
		}
	}

	int * per;
	per = new int[N];
	for (int i = 0; i < N; i++) {
		per[i] = i;
	}
	
	do {
		double p = 1;
		for (int i = 0; i < N; i++) {
			p *= jimi[per[i]][i];
		}
		ans = max(ans, p);
	} while (next_permutation(per, per + N));

	cout << fixed;
	cout.precision(8);
	cout << ans*100;

	//system("pause");
	return 0;
}
