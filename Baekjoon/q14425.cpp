#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#define ll	long long
#define pii	pair<int,int>
#define pll pair<ll, ll>
#define LINF 0x7fffffffffffffff
#define INF 0x7fffffff
using namespace std;

#define NUM_ALPHA 26
typedef struct Trie {
	bool finish;
	Trie* next[NUM_ALPHA];
	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (ll i = 0; i < NUM_ALPHA; i++) {
			if (next[i])
				delete next[i];
		}
	}
	void insert(const char* key) {
		if (*key == '\0') {
			finish = true;
			return;
		}

		ll cur = *key - 'a';
		if (next[cur] == NULL) {
			next[cur] = new Trie();
		}
		next[cur]->insert(key + 1);
	}
	bool find(const char* key) {
		if (*key == '\0') {
			return finish;
		}

		ll cur = *key - 'a';
		if (next[cur] != NULL) {
			return next[cur]->find(key + 1);
		}

		return false;
	}
	bool query(const char* key) {
		if (*key == '\0') {
			return finish;
		}
		if (finish) {
			return false;
		}

		ll cur = *key - 'a';
		if (next[cur] != NULL) {
			return next[cur]->query(key + 1);
		}

		return false;
	}
} Trie;

ll N, M, ans;
char * temp;
vector<string> s, m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Trie trie;
	cin >> N >> M;
	s.resize(N);
	m.resize(M);
	for (ll i = 0; i < N; i++) {
		cin >> s[i];
		temp = &s[i][0];
		trie.insert(temp);
	}
	for (ll i = 0; i < M; i++) {
		cin >> m[i];
		temp = &m[i][0];
		ans += trie.find(temp);
	}

	cout << ans;

	return 0;
}
