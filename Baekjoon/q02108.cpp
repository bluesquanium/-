#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, M, ans;
int avg, mid, most, range;
vector<int> m;
int cnt[9000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> m[i];
		avg += m[i];
		cnt[m[i] + 4000]++;
	}
	sort(m.begin(), m.end());
	mid = m[N / 2];
	range = m[m.size() - 1] - m[0];
	int maxi = -1, maxi_idx = -1;
	int second = 0;
	for (int i = 0; i < 9000; i++) {
		if (maxi < cnt[i]) {
			maxi = cnt[i];
			maxi_idx = i;
			second = 0;
		} else if (maxi == cnt[i] && second == 0) {
			maxi_idx = i;
			second = 1;
		}
	}
	most = maxi_idx - 4000;
	
	int plusAlpha = abs((float)((avg % N) % N) / N) >= 0.5 ? 1 : 0;
	plusAlpha = avg > 0 ? plusAlpha : -plusAlpha;
	avg /= N;
	avg += plusAlpha;
	cout << avg << '\n';
	cout << mid << '\n';
	cout << most << '\n';
	cout << range << '\n';

	return 0;
}
