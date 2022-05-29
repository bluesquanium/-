#define ll int
#define pll pair<int,int>

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        ll ans = 1;
        for(ll i = 0; i < points.size(); i++) {
            for(ll j = i + 1; j < points.size(); j++) {
                ll dy = points[i][0] - points[j][0], 
                   dx = points[i][1] - points[j][1];
                ll div = gcd(dy, dx);
                dy /= div; dx /= div;
                
                ll cnt = 0;
                for(ll k = 0; k < points.size(); k++) {
                    if(dy == 0) {
                        if(points[k][0] == points[i][0]) {
                            cnt++;
                        }
                        continue;
                    }
                    else if (dx == 0) {
                        if(points[k][1] == points[i][1]) {
                            cnt++;
                        }
                        continue;
                    }
                    if((points[i][0] - points[k][0]) % dy != 0 || (points[i][1] - points[k][1]) % dx != 0) {
                        continue;
                    }
                    
                    ll my = (points[i][0] - points[k][0]) / dy, mx = (points[i][1] - points[k][1]) / dx;
                    if(my == mx) {
                        cnt++;
                    }
                }
                ans = max(ans, cnt);
            }
        }
            
        return ans;
    }
};