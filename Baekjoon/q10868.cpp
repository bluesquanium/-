#include <iostream>
#include <algorithm>
using namespace std;

int N, M, a, b, mini = 1000000001, ans;
int m[100001];
int st_m[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		if (i % 1000 == 0 ) {
			st_m[i / 1000] = mini;
			mini = 1000000001;
		}
		else if (i == N) { // i% 1000 != 0 이면서 i == N 일 경우
			st_m[i / 1000 + 1] = mini;
			mini = 1000000001;
		}
		cin >> m[i];
		mini = min(mini, m[i]);
	}
	
	while (M--) {
		cin >> a >> b;

		ans = m[a];
		// a ~ 1000단위까지

		if ((a - 1) / 1000 == (b - 1) / 1000) {
			for (int i = a; i <= b; i++) {
				ans = min(ans, m[i]);
			}
		}
		else {
			for (int i = a; i <= b && i % 1000 != 1; i++) {
				ans = min(ans, m[i]);
			}
			for (int i = (a + 998) / 1000 + 1; i < b / 1000 + 1; i++) {
				ans = min(ans, st_m[i]);
			}
			for (int i = (b / 1000) * 1000 + 1; i <= b; i++) {
				ans = min(ans, m[i]);
			}
		}
		
		
		// 1000 ~ 1000딴위까지
		// 1000 ~ b 단위까지

		/*
		for (int i = a; i <= b; i++) {
			ans = min(ans, m[i]);
		}
		*/
		cout << ans << '\n';
	}

	//system("pause");
	return 0;
}
