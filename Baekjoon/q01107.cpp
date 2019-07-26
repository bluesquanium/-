#include <iostream>
#include <vector>
#include <algorithm>
#define BNUM	10
using namespace std;

int N, M, temp, digitNum, ans;
int bb[BNUM]; //0~9 ; 0 : 정상, 1 : 고장
vector<int> st;

void Solve(int c) {
	if (c != 0 && digitNum - 1 <= c && c <= digitNum + 1) {
		int channel = 0;
		for (int i = 0; i < st.size(); i++) {
			channel *= 10;
			channel += st[i];
		}
		ans = min(ans, abs(N - channel) + (int)st.size());
	}
	if (c < digitNum + 1) {
		for (int i = 0; i < BNUM; i++) {
			if (bb[i] == 0) {
				st.push_back(i);
				Solve(c + 1);
				st.pop_back();
			}
		}

	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		bb[temp] = 1;
	}
	temp = N;
	while (temp != 0) {
		temp /= 10;
		digitNum++;
	}

	ans = abs(N - 100);

	Solve(0);

	cout << ans;

	return 0;
}
