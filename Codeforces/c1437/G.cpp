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

ll N, M, ans;
char * temp;
vector<string> dict;
ll cost[300001];

#define NUM_ALPHA 26
typedef struct Trie {
	Trie * next[NUM_ALPHA];
	Trie * fail;
	ll visited;
	ll maxi;
	priority_queue< pll, vector<pll>, less<pll> > output;

	Trie() : visited(0), maxi(-1) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (ll i = 0; i < NUM_ALPHA; i++) {
			if (next[i]) {
				delete next[i];
			}
		}
	}
	void insert(const char * key, ll val, ll strIdx) {
		if (*key == '\0') {
			output.push({ val, strIdx });
			return;
		}

		ll cur = *key - 'a';
		if (next[cur] == NULL) {
			next[cur] = new Trie();
		}
		next[cur]->insert(key + 1, val, strIdx);
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

			//if (next->fail->output == 0) next->output = 0;

			q.push(next);
		}
	}
}

ll acQuery(string s, Trie * root, ll qIdx) {
	ll ret = -1;
	Trie * current = root;
	for (ll i = 0; i < s.size(); i++) {
		ll next = s[i] - 'a';
		while (current != root && current->next[next] == NULL) {
			current = current->fail;
		}

		if (current->next[next]) {
			current = current->next[next];
		}

		if (current->visited != qIdx) {
			current->visited = qIdx;
			while (!current->output.empty()) {
				pll cur = current->output.top();
				if (cost[cur.second] == cur.first) {
					current->maxi = cur.first;
					ret = max(ret, cur.first);
					break;
				}
				else {
					current->output.pop();
				}
			}
		}
		else {
			ret = max(ret, current->maxi);
		}

		vector<Trie *> st;
		st.push_back(current);
		ll backMaxi = -1;

		Trie * ptr = current->fail;
		while (ptr != root) {
			if (ptr->visited == qIdx) {
				backMaxi = ptr->maxi;
				ret = max(ret, ptr->maxi);
				break;
			}
			st.push_back(ptr);
			ptr->visited = qIdx;
			while (!ptr->output.empty()) {
				pll cur = ptr->output.top();
				if (cost[cur.second] == cur.first) {
					ret = max(ret, cur.first);
					ptr->maxi = cur.first;
					break;
				}
				else {
					ptr->output.pop();
				}
			}
			ptr = ptr->fail;
		}

		while (!st.empty()) {
			Trie * cur = st.back(); st.pop_back();
			backMaxi = max(cur->maxi, backMaxi);
			cur->maxi = backMaxi;
		}
	}

	return ret;
}

int main(void) {
	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	Trie trie;

	cin >> N >> M;
	dict.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> dict[i];
		temp = &dict[i][0];
		trie.insert(temp, 0, i);
	}
	AhoCorasick(&trie);
	for (ll i = 1; i <= M; i++) {
		ll cmd;
		cin >> cmd;
		if (cmd == 1) {
			ll idx, x;
			cin >> idx >> x;
			idx--;
			cost[idx] = x;
			temp = &dict[idx][0];
			trie.insert(temp, x, idx);
		}
		else {
			string s;
			cin >> s;

			cout << acQuery(s, &trie, i) << '\n';
		}
	}

	return 0;
}


