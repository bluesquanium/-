#include <iostream>
#include <cmath>
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

ll N, X, ans;
vector<ll> m;

ll mem[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (ll i = 1; i <= 1000000; i++) {
		mem[i] = mem[i - 1] + i;
	}

	cin >> N >> X;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}

	ll cnt = 0, head = N - 1, tail, tail_num, score = 0;
	for (ll i = N - 1; i >= 0; i--) {
		score += mem[m[i]];
		tail = i;
		if (cnt + m[i] >= X) {
			tail_num = X - cnt;
			score -= mem[m[i] - tail_num];
			cnt = X;
			break;
		}
		cnt += m[i];
	}
	ans = max(ans, score);

	while (head - 1 >= 0) {
		if (head == tail) {
			score = 0;
			cnt = 0;
			tail_num = 0;
		}
		else {
			score -= mem[m[head]];
			cnt -= m[head];

			score -= mem[m[tail]] - mem[m[tail] - tail_num];
			cnt -= tail_num;
			tail_num = 0;
			tail = (tail + 1) % N;
		}

		head--;
		while (1) {
			tail = (tail - 1 + N) % N;
			score += mem[m[tail]];
			if (cnt + m[tail] >= X) {
				tail_num = X - cnt;
				score -= mem[m[tail] - tail_num];
				cnt = X;
				break;
			}
			cnt += m[tail];
		}
		ans = max(ans, score);
	}

	cout << ans;

	return 0;
}
