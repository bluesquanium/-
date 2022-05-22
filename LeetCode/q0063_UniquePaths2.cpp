#define ll int
#define pll pair<ll,ll>

#define DIR 2
ll dy[DIR] = {0, 1};
ll dx[DIR] = {1, 0};

class Solution {
public:
    ll ans = 0;
    ll check[100][100];
    
    int uniquePathsWithObstacles(vector<vector<int>>& m) {
        ll Y = m.size(), X = m[0].size();
        
        for(ll i = 0; i < Y; i++) {
            for(ll j = 0; j < X; j++) {
                check[i][j] = 0;
            }
        }
        
        queue<pll> st;
        if(m[0][0] == 0) {
            st.push({0, 0});
            check[0][0] = 1;
        }
        while(!st.empty()) {
            pll cur = st.front(); st.pop();
            
            if(cur.first == Y - 1 && cur.second == X - 1) {
                // ans++;
                continue;
            }
            
            if(check[cur.first][cur.second] < 0) {
                continue;
            }
            
            
            for(ll dir = 0; dir < DIR; dir++) {
                ll ny = cur.first + dy[dir], nx = cur.second + dx[dir];
                if(
                    0 <= ny && ny < Y &&
                    0 <= nx && nx < X
                ) {
                    if(m[ny][nx] == 0) {
                        st.push({ny, nx});   
                        check[ny][nx] += check[cur.first][cur.second];
                    }
                }
            }
            
            check[cur.first][cur.second] *= -1;
        }
        
        return check[Y - 1][X - 1];
    }
};