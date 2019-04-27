#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <cstring>
#include <algorithm>
#define pii	pair<int,int>
using namespace std;

int N, K;
int m[200000];
int t[200000];
pii pointer[200001];
priority_queue<pii, vector<pii>, less<pii> > pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		pointer[i].first = -1; pointer[i].second = -1;
	}
	for (int i = 0; i < N; i++) {
		cin >> m[i];
		pq.push({ m[i], i}); 
	}

	int turn = 1;
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();

		if (t[cur.second] == 0) {
			t[cur.second] = turn;

			int count = K, cur_d = cur.second + 1;
			while (cur_d < N && count > 0) { // 삭제 단계
				if (t[cur_d] == 0) {
					t[cur_d] = turn;
					count--;
				}

				if (pointer[cur_d].second != -1) {
					cur_d = pointer[cur_d].second;
				}
				else {
					cur_d++;
				}
			}
			count = K; int cur_d2 = cur.second - 1;
			while (cur_d2 >= 0 && count > 0) { // 삭제 단계
				if (t[cur_d2] == 0) {
					t[cur_d2] = turn;
					count--;
				}

				if (pointer[cur_d2].first != -1) {
					cur_d2 = pointer[cur_d2].first;
				}
				else {
					cur_d2--;
				}
			}

			if (cur_d2 >= 0) {
				pointer[cur_d2].second = cur_d;
			}
			if (cur_d < N) {
				pointer[cur_d].first = cur_d2;
			}


			turn = (turn == 1 ? 2 : 1);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << t[i];
	}

	return 0;
}
