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
#define MOD 1000000007

ll N, M, ans, temp;
vector<string> m;

class Trie {
public:
    Trie * tree[NUM_ALPHA];
    bool finish;

    Trie() {
        for(ll i = 0; i < NUM_ALPHA; i++) {
            tree[i] = NULL;
        }
        finish = false;
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
            finish = true;
            return;
        }

        ll cur = *s - 'A';
        if(tree[cur] == NULL) {
            tree[cur] = new Trie();
        }
        tree[cur]->insert(s + 1);
    }

    bool query(const char * s) {
        if(*s == '\0') {
            return finish;
        }

        ll cur = *s - 'A';
        if(tree[cur] == NULL) {
            return false;
        }
        return tree[cur]->query(s + 1);
    }
};

ll Factorial(ll num) {
    if (num == 0) {
        return 1;
    }
    ll ret = 1;
    for(ll i = 2; i <= num; i++) {
        ret = (ret * i) % MOD;
    }
    return ret;
}

ll solve(Trie * trie) {
    ll ret = 1;
    ll cnt = trie->finish;
    for(ll i = 0; i < NUM_ALPHA; i++) {
        if(trie->tree[i] != NULL) {
            ret = (ret * solve(trie->tree[i])) % MOD;
            cnt++;
        }
    }

    return (Factorial(cnt) * ret) % MOD;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	m.resize(N);

    Trie * trie = new Trie();
	for (ll i = 0; i < N; i++) {
		cin >> m[i];
	}
    sort(m.begin(), m.end());
    for (ll i = 0; i < N; i++) {
        for(ll j = 0; j < m[i].size(); j++) {
            ll isSame = false;
            if(i - 1 >= 0 && m[i - 1].size() > j) {
                if(m[i - 1][j] == m[i][j]) {
                    isSame = true;
                }
            }
            if(i + 1 < N && m[i + 1].size() > j) {
                if(m[i + 1][j] == m[i][j]) {
                    isSame = true;
                }
            }
            
            if(isSame == false) {
                m[i] = m[i].substr(0, j + 1);
                break;
            }
        }
    }
    for (ll i = 0; i < N; i++) {
        //cout << m[i] << '\n';
        trie->insert(m[i].c_str());
	}

	cout << solve(trie) << '\n';

    delete trie;
	return 0;
}
