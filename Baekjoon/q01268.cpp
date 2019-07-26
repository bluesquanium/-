#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, ans, maxi = -1, ** m, ** check;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	m = new int*[N];
	check = new int*[N];
	for (int i = 0; i < N; i++) {
		check[i] = new int[N];
		memset(check[i], 0, sizeof(int)* N);

		m[i] = new int[5];
		for (int j = 0; j < 5; j++) 
			cin >> m[i][j];
	}

	for (int j = 0; j < 5; j++) {
		vector<int> temp[10]; // 각각은 '반'을 뜻함. 1~9
		for (int i = 0; i < N; i++) {
			if (temp[m[i][j]].size() != 0) {
				for (int k = 0; k < temp[m[i][j]].size(); k++)
					check[i][temp[m[i][j]][k]] = 1;
			}
			temp[m[i][j]].push_back(i);
		}
	}

	for (int i = 0; i < N; i++) {
		int c = 0;
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 1 || check[j][i] == 1) c++;
		}
		if (maxi < c) {
			ans = i;
			maxi = c;
		}
	}

	cout << ans+1;

	for (int i = 0; i < N; i++) {
		delete[] m[i];
		delete[] check[i];
	}
	delete[] m;
	delete[] check;

	return 0;
}
