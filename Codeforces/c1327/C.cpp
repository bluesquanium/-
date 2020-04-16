#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<ll,ll>
using namespace std;

ll N, M, K, t1, t2, ans;
string seq;
vector<ll> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M >> K;
	for (int k = 0; k < K; k++) {
		cin >> t1 >> t2;
	}
	for (int k = 0; k < K; k++) {
		cin >> t1 >> t2;
	}

	for (int i = 0; i < N - 1; i++) {
		seq += "U";
	}
	for (int i = 0; i < M - 1; i++) {
		seq += "L";
	}
	int dir = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 1; j++) {
			if (dir == 1) {
				seq += "R";
			}
			else {
				seq += "L";
			}
		}
		seq += "D";

		dir *= -1;
	}

	cout << seq.size() << '\n';
	for (int i = 0; i < seq.size(); i++) {
		cout << seq[i];
	}


	return 0;
}
