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

ll N, M, temp;
double ans;
vector<string> m;

#define NUM_ALPHA 26
class Trie {
public:
    ll finish;
    Trie * tree[NUM_ALPHA];

    Trie() {
        finish = 0;
        for(ll i = 0; i < NUM_ALPHA; i++) {
            tree[i] = NULL;
        }
    }

    ~Trie() {
        for(ll i = 0; i < NUM_ALPHA; i++) {
            if(tree[i] != NULL) {
                delete tree[i];
            }
        }
    }

    void insert(const char * s) {
        if(*s == '\0') {
            finish = 1;
            return;
        }

        ll cur = *s - 'a';
        if(tree[cur] == NULL) {
            tree[cur] = new Trie();
        }
        tree[cur]->insert(s + 1);
        return;
    }

    bool query(const char * s) {
        if(*s == '\0') {
            return finish;
        }

        ll cur = *s - 'a';
        if(tree[cur] == NULL) {
            return 0;
        }
        return tree[cur]->query(s + 1);
    }
};

void Cal(Trie * trie, ll cnt) {
    if(trie->finish) {
        ans += cnt;
        //cout << "cnt: " << cnt << '\n';
    }

    ll numChild = 0;
    for(ll i = 0; i < NUM_ALPHA; i++) {
        if(trie->tree[i] != NULL) {
            numChild++;
        }
    }
    if(numChild > 1 || trie->finish) {
        cnt++;
    }
    for(ll i = 0; i < NUM_ALPHA; i++) {
        if(trie->tree[i] != NULL) {
            Cal(trie->tree[i], cnt);
        }
    }

    return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
    while(cin >> N) {
        Trie trie;
        ans = 0;
        m.resize(N);

        for (ll i = 0; i < N; i++) {
            cin >> m[i];
            trie.insert(m[i].c_str());
        }

        for(ll i = 0; i < NUM_ALPHA; i++) {
            if(trie.tree[i] != NULL)
                Cal(trie.tree[i], 1);
        }
        
        cout << fixed;
        cout.precision(2);
        cout << ans / N << '\n';
    }

	return 0;
}
