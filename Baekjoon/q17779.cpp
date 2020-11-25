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

ll N, ans, temp;
ll m[20][20];
ll check[20][20];

ll Cal(pll a, pll b) {
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            check[i][j] = 0;
        }
    }
    
    ll mini = INF, maxi = 0;
    pll left_vertex; left_vertex.first = (a.first + a.second + b.first - b.second) / 2; left_vertex.second = (a.first + a.second - b.first + b.second) / 2;
    pll right_vertex; right_vertex.first = (a.first - a.second + b.first + b.second) / 2; right_vertex.second = (-a.first + a.second + b.first + b.second) / 2;

    if( (a.first + a.second + b.first - b.second) % 2 == 1 || 
        (a.first + a.second - b.first + b.second) % 2 == 1 ||
        (a.first - a.second + b.first + b.second) % 2 == 1 ||
        (-a.first + a.second + b.first + b.second) % 2 == 1) {
        return INF;
    }
    if( left_vertex.first < 0 || left_vertex.first >= N ||
        left_vertex.second < 0 || left_vertex.second >= N ||
        right_vertex.first < 0 || right_vertex.first >= N ||
        right_vertex.second < 0 || right_vertex.second >= N) {
            return INF;
    }

    ll zone[6] = {0};
    for(ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            // zone[5];
            if( i + j >= a.first + a.second &&
                i - j >= a.first - a.second &&
                i + j <= b.first + b.second &&
                i - j <= b.first - b.second ) {
                zone[5] += m[i][j];
                check[i][j] = 5;
                continue;
            }
            
            if (i + j >= a.first + a.second) {
                if(i + j <= b.first + b.second) { // middle
                    if(i - j <= a.first - a.second) {
                        zone[2] += m[i][j];
                        check[i][j] = 2;
                    } 
                    else {
                        zone[4] += m[i][j];
                        check[i][j] = 4;
                    }
                } 
                else { // bottom
                    if(i - j >= a.first - a.second) {
                        if(i - j <= b.first - b.second) { // middle
                            zone[3] += m[i][j];
                            check[i][j] = 3;
                        }
                        else { // bottom
                            if(j >= b.second) {
                                zone[3] += m[i][j];
                                check[i][j] = 3;
                            } else {
                                zone[4] += m[i][j];
                                check[i][j] = 4;
                            }
                        }
                    }
                    else { // top
                        if(i <= right_vertex.first) {
                            zone[2] += m[i][j];
                            check[i][j] = 2;
                        } else {
                            zone[3] += m[i][j];
                            check[i][j] = 3;
                        }
                    }
                }
            }
            else { // top
                if(i - j >= a.first - a.second) {
                    if(i - j <= b.first - b.second) { // middle
                        zone[1] += m[i][j];
                        check[i][j] = 1;
                    } 
                    else { //bottom
                        if(i >= left_vertex.first) {
                            zone[4] += m[i][j];
                            check[i][j] = 4;
                        } else {
                            zone[1] += m[i][j];
                            check[i][j] = 1;
                        }
                    }
                }
                else { // top
                    if(j <= a.second) {
                        zone[1] += m[i][j];
                        check[i][j] = 1;
                    }
                    else {
                        zone[2] += m[i][j];
                        check[i][j] = 2;
                    }
                }
            }
        }
    }
    // i + j > a.first + a.second;
    // i - j > a.first - a.second;

    // i + j < b.first + b.second;
    // i - j < b.first - b.second;

    for(ll i = 1; i <= 5; i++) {
        if(mini > zone[i]) {
            mini = zone[i];
        }
        if(maxi < zone[i]) {
            maxi = zone[i];
        }
    }

    // cout << "---a:(" << a.first << ", " << a.second << "), b(" << b.first << ", " << b.second << ")----\n";
    // for(ll i = 0; i < N; i++) {
    //     for(ll j = 0; j < N; j++) {
    //         cout << check[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "-------\n";

    return maxi - mini;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (ll i = 0; i < N; i++) {
        for(ll j = 0; j < N; j++) {
            cin >> m[i][j];
        }
	}

    ans = INF;
    pll point[2];
    for (ll i = 0; i < N - 1; i++) {
        for(ll j = 1; j < N - 1; j++) {
            point[0].first = i; point[0].second = j;
            // i + j > point[0].first + point[0].second;
            // i - j > point[0].first - point[0].second;
            for(ll i2 = i + 2; i2 < N; i2++) {
                for(ll j2 = 1; j2 < N - 1; j2++) {
                    if(i2 + j2 <= point[0].first + point[0].second || i2 - j2 <= point[0].first - point[0].second) {
                        continue;
                    }
                    point[1].first = i2; point[1].second = j2;
                    ans = min(ans, Cal(point[0], point[1]));
                }
            }
        }
	}
	
	cout << ans << '\n';

	return 0;
}
