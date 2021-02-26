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

ll N, Q, ans;
char * temp;

#define NUM_ALPHA 26
typedef struct Trie {
	bool isRoot;
	Trie * next[NUM_ALPHA];
	Trie * fail;
	ll output;

	Trie() : output(0), isRoot(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (ll i = 0; i < NUM_ALPHA; i++) {
			if (next[i]) {
				delete next[i];
			}
		}
	}
	void insert(const char * key) {
		if (*key == '\0') {
			output = 1;
			return;
		}

		ll cur = *key - 'a';
		if (next[cur] == NULL) {
			next[cur] = new Trie();
		}
		next[cur]->insert(key + 1);
	}
	ll find(const char * key) {
		if (*key == '\0') {
			return output;
		}

		ll cur = *key - 'a';
		if (next[cur] == NULL) {
			return 0;
		}
		return next[cur]->find(key + 1);
	}
} Trie;

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
		else {
			Trie * ptr = current->fail;
			while (ptr != root) {
				if (ptr->output) {
					return 1;
				}
				ptr = ptr->fail;
			}
		}
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Trie trie;
	trie.isRoot = true;

	cin >> N;
	for (ll i = 0; i < N; i++) {
		string s;
		cin >> s;
		temp = &s[0];
		trie.insert(temp);
	}
	AhoCorasick(&trie);

	cin >> Q;
	for (ll i = 0; i < Q; i++) {
		string s;
		cin >> s;
		temp = &s[0];

		if (acQuery(s, &trie)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
