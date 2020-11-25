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
vector<pll> lines;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(ll i = 0; i < N; i++) {
        ll from, to;
        cin >> from >> to;
        if(from > to) {
            swap(from, to);
        }
        lines.push_back({from, to});
    }
    sort(lines.begin(), lines.end());

    ll curEnd = -INF;
    for(ll i = 0; i < N; i++) {
        if(curEnd <= lines[i].first) {
            ans += lines[i].second - lines[i].first;
            curEnd = lines[i].second;
        } else {
            if(lines[i].second > curEnd) {
                ans += lines[i].second - curEnd;
                curEnd = lines[i].second;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
