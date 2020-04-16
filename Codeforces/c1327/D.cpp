#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int T, N, M, ans;
vector<int> p, c;

vector< vector<ll> > factors;
void updateFactors(int n) {
	factors.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			factors[j].push_back(i);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	updateFactors(200000);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		ans = N;
		p.resize(N); c.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> p[i]; p[i]--;
		}
		for (int i = 0; i < N; i++) {
			cin >> c[i];
		}

		for (int i = 0; i < N; i++) {
			if (p[i] != -1) {
				vector<int> cycle;
				for (int j = i; p[j] != -1;) {
					cycle.push_back(c[j]);
					int nj = p[j];
					p[j] = -1;
					j = nj;
				}

				for (int k : factors[int(cycle.size())]) {
					for (int a = 0; a < k; a++) {
						bool check = true;
						for (int v = a; v < int(cycle.size()); v += k) {
							check = check && cycle[a] == cycle[v];
						}
						if (check) {
							ans = min(ans, k);
						}
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
