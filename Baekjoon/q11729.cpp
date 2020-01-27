#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
using namespace std;

int N, ans;
vector<pii> seq;

void hanoi(int from, int mid, int dst, int num) {
	if (num == 1) {
		seq.push_back({ from ,dst });
		ans++;
		return;
	}
	hanoi(from, dst, mid, num - 1);
	seq.push_back({ from ,dst });
	ans++;
	hanoi(mid, from, dst, num - 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	hanoi(1, 2, 3, N);
	cout << ans << '\n';
	for (int i = 0; i < seq.size(); i++) {
		cout << seq[i].first << ' ' << seq[i].second << '\n';
	}

	return 0;
}
