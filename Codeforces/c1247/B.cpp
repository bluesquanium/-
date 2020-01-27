#include <iostream>
using namespace std;

int T, N, K, D, i, base, ans, conse;
int a[200000];
int dict[1000001];

int main(void) {
	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;

	while (T--) {
		ans = conse = base = 0;
		cin >> N >> K >> D;
		for (i = 1; i <= K; i++) {
			dict[i] = 0;
		}
		for (i = 0; i < N; i++) {
			cin >> a[i];
		}

		for (i = 0; i < D; i++) {
			if (dict[a[i]]++ == 0) {
				conse++;
			}
		}
		ans = conse;
		for (; i < N; i++) {
			if (dict[a[i]]++ == 0) {
				conse++;
			}

			if (--dict[a[base++]] == 0) {
				conse--;
			}

			ans = conse < ans ? conse : ans;
		}

		cout << ans << '\n';
	}

	return 0;
}
