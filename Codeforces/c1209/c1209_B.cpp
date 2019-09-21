#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define pii	pair<int,int>
using namespace std;

int N, ans, t1, t2;
string s;
vector<pii> ab;
vector<bool> state;
vector<int> timer;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> s;
	state.resize(N);
	timer.resize(N, 0);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			state[i] = 0;
		}
		else {
			state[i] = 1;
			ans++;
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> t1 >> t2;
		ab.push_back({ t1,t2 });
	}

	for (int i = 1; i <= 130; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if (ab[j].second <= i) {
				if (timer[j] == 0) {
					state[j] = !state[j];
					timer[j] = ab[j].first - 1;
				}
				else {
					timer[j]--;
				}
			}
			if (state[j] == 1) {
				sum++;
			}
		}
		ans = max(ans, sum);
	}


	cout << ans;

	return 0;
}
