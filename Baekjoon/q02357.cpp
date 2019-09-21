#include <iostream>
#include <vector>
#include <algorithm>
#define pii	pair<int,int>
using namespace std;

int N, M, s, c, t1, t2;
pii ans;
vector<pii> m, r; // r : range

int getParent(int cur) {
	return cur / 2;
}

void update_r(int cur) {
	while (cur != 0) {
		if (r[cur * 2].first == -1) {
			r[cur] = r[cur * 2 + 1];
		}
		else if (r[cur * 2 + 1].first == -1) {
			r[cur] = r[cur * 2];
		}
		else {
			r[cur] = { r[cur * 2].first, r[cur * 2 + 1].second };
		}

		cur--;
	}
	return;
}

void update_p(int cur) {
	if (cur == 0) return;
	else {
		if (m[cur * 2].second == -1) {
			m[cur] = m[cur * 2 + 1];
		}
		else if (m[cur * 2 + 1].second == -1) {
			m[cur] = m[cur * 2];
		}
		else {
			m[cur] = { max(m[cur * 2].first, m[cur * 2 + 1].first), min(m[cur * 2].second, m[cur * 2 + 1].second) };
		}
		
		update_p(getParent(cur));
	}
}

void update(int cur, int num, int seq) {
	m[cur] = { num, num };
	r[cur] = { seq, seq };
	update_p(getParent(cur));
}

pii search(int begin, int end, pii range, int cur) {
	if (end < range.first || range.second < begin) {
		return { -1, 1000000001 }; // Trash value
	}
	else if (begin <= range.first && range.second <= end) {
		return m[cur];
	}
	else {
		pii s1 = search(begin, end, r[cur * 2], cur * 2),
			s2 = search(begin, end, r[cur * 2 + 1], cur * 2 + 1);
		return  { max(s1.first, s2.first), min(s1.second, s2.second) };
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i < N; i = i * 2) {
		s += i;
		if (i * 2 >= N) {
			c = s + 1;
			s += i * 2 + 1;
		}
	}
	if (s == 0) s = 1;
	m.resize(s, { -1, -1 });
	r.resize(s, { -1, -1 });

	for (int i = 0; i < N; i++) {
		cin >> t1;
		update(c+i, t1, i+1);
	}
	update_r(c-1);

	/*
	for (int i = 0; i < s; i++) {
		cout << m[i].first << ", " << m[i].second << endl;
	}
	cout << "range" << endl;
	for (int i = 0; i < s; i++) {
		cout << r[i].first << ", " << r[i].second << endl;
	}
	*/

	for (int i = 0; i < M; i++) {
		cin >> t1 >> t2;
		ans = search(t1, t2, r[1], 1);
		cout << ans.second << ' ' << ans.first << '\n';
	}

	return 0;
}
