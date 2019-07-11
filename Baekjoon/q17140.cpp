#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define MAX	100
#define pii pair<int,int>
using namespace std;

int R, C, K, ans = 1;
int m[MAX][MAX], temp_m[MAX][MAX];

struct cmp {
	bool operator()(pii a, pii b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		else {
			return a.first > b.first;
		}
	}
};

void solve(int row, int col) {
	if (ans > 100) return;

	memset(temp_m, 0, sizeof(int)*MAX*MAX);
	if (row >= col) { // R 연산 ->
		int max_c = 0;
		for (int i = 0; i < MAX; i++) {
			//if (m[i][0] == 0) break;

			priority_queue<pii, vector<pii>, cmp> pq;
			map<int, int> c;
			int cur = 0;
			for (int j = 0; j < MAX; j++) {
				if (m[i][j] == 0) continue;
				
				if (c.count(m[i][j]) == 0) {
					c[m[i][j]] = 1;
				}
				else {
					c[m[i][j]]++;
				}
			}
			for (auto iter = c.begin(); iter != c.end(); iter++) {
				pq.push({ (*iter).second, (*iter).first });
			}
			while (!pq.empty()) {
				pii value = pq.top(); pq.pop();
				temp_m[i][cur++] = value.second;
				temp_m[i][cur++] = value.first;
			}
			
			max_c = max(max_c, cur); // col 업데이트
		}
		col = max_c;
	}
	else { // C연산 |
		int max_r = 0;
		for (int i = 0; i < MAX; i++) {
			//if (m[0][i] == 0) break;

			priority_queue<pii, vector<pii>, cmp > pq;
			map<int, int> c;
			int cur = 0;
			for (int j = 0; j < MAX; j++) {
				if (m[j][i] == 0) continue;

				if (c.count(m[j][i]) == 0) {
					c[m[j][i]] = 1;
				}
				else {
					c[m[j][i]]++;
				}
			}
			for (auto iter = c.begin(); iter != c.end(); iter++) {
				pq.push({ (*iter).second, (*iter).first });
			}
			while (!pq.empty()) {
				pii value = pq.top(); pq.pop();
				temp_m[cur++][i] = value.second;
				temp_m[cur++][i] = value.first;
			}

			max_r = max(max_r, cur); // row 업데이트
		}
		row = max_r;
	}

	for (int i = 0; i < MAX; i++) {
		//if (temp_m[i][0] == 0) break;
		for (int j = 0; j < MAX; j++) {
			//if (temp_m[i][j] == 0) break;
			m[i][j] = temp_m[i][j];
		}
	}

	if (m[R][C] == K) {
		return;
	}
	else {
		ans++;
		solve(row, col);
	}
}

int main(void) {
	cin >> R >> C >> K;
	R--; C--;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> m[i][j];
		}
	}
	
	if (m[R][C] == K) {
		cout << 0;
		return 0;
	}

	solve(3, 3);

	if (ans > 100) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}
