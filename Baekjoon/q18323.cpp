#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, check;
int used[1001];
vector<int> ans;
vector<int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N-1);
	ans.resize(N);
	for (int i = 0; i < N-1; i++) {
		cin >> m[i];
	}

	for (int i = 1; i <= N; i++) {
		used[i] = i;
		int prev = i;
		check = 1;
		ans.clear();
		ans.push_back(i);
		for (int j = 0; j < N - 1; j++) {
			int x = m[j] - prev;
			if ( x > 0 && x <= N && used[x] != i) {
				ans.push_back(x);
				used[x] = i;
				prev = x;
			}
			else {
				check = 0;
				break;
			}
		}

		if (check) {
			for (int j = 0; j < N; j++) {
				cout << ans[j] << ' ';
			}
			break;
		}
	}

	return 0;
}
