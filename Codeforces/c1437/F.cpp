#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long
#define INF 0x7fffffff
#define LINF 0x7fffffffffff
#define MOD 998244353
#define pll pair<ll, ll>
using namespace std;
 
ll N, ans;
vector<ll> m;
vector<pll> maxs;
ll mem[5001][5000];
 
int main(void) {
    cin >> N;
    m.resize(N);
    for(ll i = 0; i < N; i++) {
        cin >> m[i];
    }
    sort(m.begin(), m.end());
 
    ll curVal = m[0], cnt = 0, mcur = 0;
    for(ll i = 0; i < N; i++) {
        if(curVal == m[i]) {
            cnt++;
        } else {
            maxs.push_back({m[i - 1], cnt});
            mem[1][mcur++] = cnt;
            cnt = 1;
            curVal = m[i];
        }
    }
    maxs.push_back({m.back(), cnt});
    mem[1][mcur] = cnt;
 
    // for(ll i = 0; i < maxs.size(); i++) {
    //     cout << maxs[i].first << ' ' << maxs[i].second << '\n';
    // }
 
    for(ll i = 2; i <= N; i++) {
        ll cur = 0, sum = 0, candi_num = 0;
        for(ll j = 0; j < maxs.size(); j++) {
            while(j > cur) {
                if(maxs[j].first < 2 * maxs[cur].first) {
                    break;
                }
 
                sum += mem[i - 1][cur];
                sum = sum % MOD;
                candi_num += maxs[cur].second;
                cur++;
            }
 
            mem[i][j] = sum * maxs[j].second + mem[i - 1][j] * (candi_num + 1 - (i - 1));
            mem[i][j] = mem[i][j] % MOD;
            if(mem[i][j] < 0) {
                mem[i][j] = 0;
            }
        }
    }
 
    // for(ll i = 1; i <= N; i++) {
    //     for(ll j = 0; j < maxs.size(); j++) {
    //         cout << mem[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
 
    cout << mem[N][maxs.size() - 1] << '\n';
 
    return 0;
}
