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

#define DIR 6
// z+ z- y+ y- x+ x-
ll dz[DIR] = {1, -1, 0,  0, 0,  0};
ll dy[DIR] = {0,  0, 1, -1, 0,  0};
ll dx[DIR] = {0,  0, 0,  0, 1, -1};

ll N, M, H, ans, temp;
ll m[100][100][100];
ll visited[100][100][100];

class Point {
public:
    ll z, y, x;
    Point(ll _z, ll _y, ll _x) {
        z = _z;
        y = _y;
        x = _x;
    }
};
vector<Point> st;

void solve() {
    ans = 0;
    while(!st.empty()) {
        // cout << ans << ": " << st.size() << '\n';
        vector<Point> st2;
        while(!st.empty()) {
            Point cur = st.back(); st.pop_back();
            // cout << "(" << cur.z << ' ' << cur.y << ' ' << cur.x << ")\n";

            for(ll dir = 0; dir < DIR; dir++) {
                ll nz = cur.z + dz[dir], ny = cur.y + dy[dir], nx = cur.x + dx[dir];
                if( 0 <= nz && nz < H &&
                    0 <= ny && ny < N &&
                    0 <= nx && nx < M ) {
                    if(m[nz][ny][nx] == 0) {
                        visited[nz][ny][nx] = 1;
                        m[nz][ny][nx] = 1;
                        st2.push_back(Point(nz, ny, nx));
                    }
                }
            }
        }
        st = st2;
        if(st2.size() != 0) {
            ++ans;
        }
    }

    for (ll i = 0; i < H; i++) {
		for(ll j = 0 ; j < N; j++) {
            for(ll k =0; k < M; k++) {
                if(m[i][j][k] == 0) {
                    ans = -1;
                    return;
                }
            }
        }
    }
    return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
    ll hasTarget = 0;
	cin >> M >> N >> H;
	for (ll i = 0; i < H; i++) {
		for(ll j = 0 ; j < N; j++) {
            for(ll k = 0; k < M; k++) {
                cin >> m[i][j][k];
                
                if(m[i][j][k] == 1) {
                    st.push_back(Point(i, j, k));
                }
                else if(m[i][j][k] == 0) {
                    hasTarget = 1;
                }
            }
        }
	}

    if(st.size() == 0 && hasTarget == 1) {
        ans = -1;
    } else {
        solve();
    }
	
	cout << ans << '\n';

	return 0;
}
