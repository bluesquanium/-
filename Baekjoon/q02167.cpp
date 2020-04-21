#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

ll N, M, K, ans, I, J, X, Y;
ll m[301][301];
ll mem[301][301];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> m[i][j];
			mem[i][j] = mem[i][j - 1] + m[i][j];
		}
	}
	cin >> K;
	for (int k = 0; k < K; k++) {
		ans = 0;
		cin >> I >> J >> X >> Y;
		for (int i = I; i <= X; i++) {
			ans += mem[i][Y] - mem[i][J - 1];
		}
		cout << ans << '\n';
	}

	return 0;
}
