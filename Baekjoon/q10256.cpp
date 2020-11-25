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

ll T, N, M, ans;
char * temp;
string S, P;

#define NUM_ALPHA 4
typedef struct Trie {
	Trie * next[NUM_ALPHA];
	Trie * fail;
	ll output;

	Trie() : output(0) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (ll i = 0; i < NUM_ALPHA; i++) {
			if (next[i] != NULL) {
				delete next[i];
			}
		}
	}
	void insert(const char * key) {
		if (*key == '\0') {
			output = 1;
			return;
		}

		ll cur;
		switch (*key) {
		case 'A':
			cur = 0;
			break;
		case 'C':
			cur = 1;
			break;
		case 'G':
			cur = 2;
			break;
		case 'T':
			cur = 3;
			break;
		}
		if (next[cur] == NULL) {
			next[cur] = new Trie();
		}
		next[cur]->insert(key + 1);
	}
} Trie;

void AhoCorasick(Trie * root) {
	root->fail = root;
	queue<Trie *> q;
	q.push(root);

	while (!q.empty()) {
		Trie * current = q.front(); q.pop();

		for (ll i = 0; i < NUM_ALPHA; i++) {
			Trie * next = current->next[i];
			if (next == NULL) {
				continue;
			}

			if (current == root) {
				next->fail = root;
			}
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

			if (next->fail->output) {
				next->output = 1;
			}

			q.push(next);
		}

	}
}

ll acQuery(string s, Trie * root) {
	ll ret = 0;
	Trie * current = root;
	for (ll i = 0; i < s.size(); i++) {
		ll next;
		switch (s[i]) {
		case 'A':
			next = 0;
			break;
		case 'C':
			next = 1;
			break;
		case 'G':
			next = 2;
			break;
		case 'T':
			next = 3;
			break;
		}

		while (current != root && current->next[next] == NULL) {
			current = current->fail;
		}

		if (current->next[next]) {
			current = current->next[next];
		}

		if (current->output) {
			ret++;
		}
	}

	return ret;
}

string Reverse(string s, ll start, ll end) {
	string ret = s;
	for (ll i = 0; i < end - start + 1; i++) {
		ret[start + i] = s[end - i];
	}

	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (ll t = 1; t <= T; t++) {
		Trie trie;

		cin >> N >> M;
		cin >> S;
		cin >> P;

		temp = &P[0];
		trie.insert(temp);
		for (ll i = 0; i < M; i++) {
			for (ll j = i + 1; j < M; j++) {
				string s = Reverse(P, i, j);
				temp = &s[0];
				trie.insert(temp);
			}
		}
		AhoCorasick(&trie);

		cout << acQuery(S, &trie) << '\n';
	}

	return 0;
}
