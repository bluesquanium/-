#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set> // set으로도 나중에 해보자.
#include <cstring>
#include <algorithm>
#define pii	pair<int,int>
using namespace std;

int N, K;
vector<pii> st;
set<int> idx;
set<int>::iterator iter;
int t[200000];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL), cin.tie(NULL);

	cin >> N >> K;
	st.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> st[i].first;
		st[i].second = i;

		idx.insert(i);
	}
	sort(st.begin(), st.end());
	
	int turn = 1;
	while (!st.empty()) {
		while (!idx.count(st.back().second)) {
			st.pop_back();
		}
		pii cur = st.back(); st.pop_back();

		vector<int> add;
		//auto it = idx.find(cur.second);
		iter = idx.find(cur.second);
		for (int i = 0; i <= K; i++) {
			add.push_back(*iter);
			if (iter == idx.begin()) break;
			iter--;
		}
		iter = next(idx.find(cur.second));
		for (int i = 0; i < K; i++) {
			if (iter == idx.end()) break;
			add.push_back(*iter);
			iter++;
		}

		while (!add.empty()) {
			idx.erase(add.back());
			t[add.back()] = turn;
			add.pop_back();
		}

		turn = (turn == 1 ? 2 : 1);
	}

	for (int i = 0; i < N; i++) {
		cout << t[i];
	}

	return 0;
}

