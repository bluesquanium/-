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

// ------------------------------- trie ------------------------------- //

// 문자열에 포함되는 후보군들의 종류에 맞게 수정.
// 추가적으로, next, find, query의 cur 값 구하는 방식도 필히 수정해야함.
#define NUM_ALPHA 10 
typedef struct Trie {
	bool finish;
	Trie* next[NUM_ALPHA];
	Trie * fail;
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

		ll cur = *key - '0';
		if (next[cur] == NULL) {
			next[cur] = new Trie();
		}
		next[cur]->insert(key + 1);
	}
	bool find(const char* key) {
		if (*key == '\0') {
			return finish;
		}

		ll cur = *key - '0';
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

		ll cur = *key - '0';
		if (next[cur] != NULL) {
			return next[cur]->query(key + 1);
		}

		return false;
	}
} Trie;

// ------------------------------ /trie ------------------------------- //

// --------------------- Aho-Corasick expansion ----------------------- //
void AhoCorasick(Trie * root) {
	queue<Trie *> q;
	root->fail = root;
	q.push(root);

	while (!q.empty()) {
		Trie * current = q.front(); q.pop();
		
		for (ll i = 0; i < NUM_ALPHA; i++) {
			Trie * next = current->next[i];
			if (next == NULL) {
				continue;
			}

			if (current == root) next->fail = root;
			else {
				Trie * dest = current->fail;
				while (dest != root && dest->next[i] == NULL) {
					dest = dest->fail;
				}

				if (dest->next[i] != NULL) {
					dest = dest->next[i];
				}
				next->fail = dest;
			}

			if (next->fail->output) next->output = 1;

			q.push(next);
		}
	}
}

ll acQuery(string s, Trie * root) {
	Trie * current = root;
	for (ll i = 0; i < s.size(); i++) {
		ll next = s[i] - 'a';
		while (current != root && !current->next[next]) {
			current = current->fail;
		}

		if (current->next[next]) {
			current = current->next[next];
		}

		if (current->output) {
			return 1;
		}

	}
	return 0;
}

// --------------------- /Aho-Corasick expansion ---------------------- //

ll T, N;
vector<string> m;
bool ans;
char * temp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		Trie trie;
		cin >> N;
		m.resize(N);
		for (ll i = 0; i < N; i++) {
			cin >> m[i];
			temp = &m[i][0];
			trie.insert(temp);
		}
		ans = true;
		for (ll i = 0; i < N; i++) {
			temp = &m[i][0];
			ans = ans && trie.query(temp);
		}

		if (ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
