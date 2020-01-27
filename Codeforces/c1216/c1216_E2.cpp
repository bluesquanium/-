#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define SIZE	200000000
#define ll	long long
#define pii	pair<int,int>
using namespace std;

ll N, M, ans;
vector<int> q;
ll mem[SIZE+1];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	q.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> q[i];
	}

	/*
	string s;
	for (int k = 1; k <= 100; k++) {
		for (int l = 1; l <= k; l++) {
			s += to_string(l);
		}
	}
	for (int i = 0; i < N; i++) {
		cout << s[q[i]-1] << '\n';
	}
	*/

	ll alpha = 0, step = 0;
	for (int i = 1; i <= SIZE; i++) {
		if (i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) step++;
		alpha += step;
		mem[i] = mem[i - 1] + i + alpha;
	}
	for (int i = 0; i < N; i++) {
		ll query = q[i];
		for (int j = 1; j <= SIZE; j++) {
			if (query <= mem[j]) {
				q[i] -= mem[j-1];
				string temp;
				for (int k = 1; k <= j; k++) {
					temp += to_string(k);
				}
				//cout << temp << '\n';
				cout << temp[q[i]-1] << '\n';
				break;
			}
		}
	}

	return 0;
}
