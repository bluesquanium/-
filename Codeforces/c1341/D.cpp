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

ll N, K, ans, cnt;
vector<string> m;
string mem[2][2001];

char num[10][8] = {
	"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

ll Cost(string s, ll target) {
	ll cost = 0;
	for (ll i = 0; i < 7; i++) {
		if (s[i] == '1' && num[target][i] == '0') {
			cost = -1;
			break;
		}
		cost += num[target][i] - s[i];
	}
	return cost;
}

string findBigger(string a, string b) {
	for (ll i = 0; i < a.size() && i < b.size(); i++) {
		if (a[i] > b[i]) {
			return a;
		}
		else if (a[i] < b[i]) {
			return b;
		}
	}
	if (a.size() == b.size()) {
		return a;
	}
	else if (a.size() > b.size()) {
		return a;
	}
	else {
		return b;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N >> K;
	m.resize(N);
	
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}

	for (ll j = 0; j < 10; j++) {
		ll cost = Cost(m[N-1], j);
		if (cost != -1) {
			string t; t.push_back(j + '0');
			mem[(N+1) % 2][cost] = t;
		}
	}

	for (ll i = N-2; i >= 0; i--) {
		for (ll k = 0; k <= K; k++) {
			mem[i % 2][k] = "";
		}
		for (ll j = 9; j >= 0; j--) {
			ll cost = Cost(m[i], j);
			if (cost != -1) {
				for (ll k = cost; k <= K; k++) {
					if (mem[(i + 1) % 2][k - cost] != "") {
						string t; t.push_back(j + '0');
						if (mem[i % 2][k] == "") {
							mem[i % 2][k] = t + mem[(i + 1) % 2][k - cost];
						}
					}
				}
			}
		}
	}
	
	if (mem[0][K] == "") {
		cout << "-1";
	}
	else {
		cout << mem[0][K];
	}

	return 0;
}
