#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define ll	int
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

#define MAX 1000000
#define SEG 1000

ll N, Q, q, ans;
vector<ll> m;
ll mem[MAX + 1];
ll segs[SEG];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> Q;
	m.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
		m[i]--;
		mem[m[i]]++;
	}
	for (ll i = 0; i * SEG < N; i++) {
		ll sum = 0;
		for (ll j = i * SEG; j < i * SEG + SEG && j < N; j++) {
			sum += mem[j];
		}
		segs[i] = sum;
	}
	for (ll i = 0; i < Q; i++) {
		cin >> q;
		if (q < 0) {
			ll target = -q;
			ll cnt = 0;
			bool check = false;
			for (ll j = 0; j < SEG; j++) {
				if (target <= cnt + segs[j]) {
					for (ll k = 0; k < SEG; k++) {
						cnt += mem[j * SEG + k];
						if (target <= cnt) {
							mem[j * SEG + k]--;
							segs[j]--;
							check = true;
							break;
						}
					}
					
				}
				cnt += segs[j];

				if (check) {
					break;
				}
			}
		}
		else {
			q--;
			mem[q]++;
			segs[q / SEG]++;
		}
	}

	for (ll i = 0; i < SEG; i++) {
		if (segs[i] > 0) {
			for (ll j = i * SEG; j < i * SEG + SEG && j < N; j++) {
				if (mem[j] > 0) {
					cout << j + 1;
					return 0;
				}
			}
		}
	}

	cout << 0;

	return 0;
}
