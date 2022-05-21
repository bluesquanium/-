#define ll int

ll m[9][9];
ll ans[9][9];
ll cases[9][9] = {
    0, 0, 0, 1, 1, 1, 2, 2, 2,
    0, 0, 0, 1, 1, 1, 2, 2, 2,
    0, 0, 0, 1, 1, 1, 2, 2, 2,
    3, 3, 3, 4, 4, 4, 5, 5, 5,
    3, 3, 3, 4, 4, 4, 5, 5, 5,
    3, 3, 3, 4, 4, 4, 5, 5, 5,
    6, 6, 6, 7, 7, 7, 8, 8, 8,
    6, 6, 6, 7, 7, 7, 8, 8, 8,
    6, 6, 6, 7, 7, 7, 8, 8, 8,
};

class Solution {
public:
    void solve(ll pos) {
        if(pos == 81) {
            for(ll i = 0; i < 9; i++) {
                for(ll j = 0; j < 9; j++) {
                    ans[i][j] = m[i][j] + '0';
                }
            }
            return;
        }
        
        // y: pos / 9, x: pos % 9;
        ll y = pos / 9, x = pos % 9;
        
        if(m[y][x] == 0) {
            ll candi[10];
            for(ll i = 1; i <= 9; i++) {
                candi[i] = 1;
            }
            for(ll i = 0; i < 9; i++) {
                if(y == i) continue;
                candi[m[i][x]] = 0;
            }
            for(ll j = 0; j < 9; j++) {
                if(x == j) continue;
                candi[m[y][j]] = 0;
            }
            ll curCase = cases[y][x];
            switch(curCase) {
                case 0:
                    for(ll i = 0; i < 3; i++) {
                        for(ll j = 0; j < 3; j++) {
                            candi[m[i][j]] = 0;
                        }
                    }
                    break;
                case 1:
                    for(ll i = 0; i < 3; i++) {
                        for(ll j = 3; j < 6; j++) {
                            candi[m[i][j]] = 0;
                        }
                    }
                    break;
                case 2:
                    for(ll i = 0; i < 3; i++) {
                        for(ll j = 6; j < 9; j++) {
                            candi[m[i][j]] = 0;
                        }
                    }
                    break;
                case 3:
                    for(ll i = 3; i < 6; i++) {
                        for(ll j = 0; j < 3; j++) {
                            candi[m[i][j]] = 0;
                        }
                    }
                    break;
                case 4:
                    for(ll i = 3; i < 6; i++) {
                        for(ll j = 3; j < 6; j++) {
                            candi[m[i][j]] = 0;
                        }
                    }
                    break;
                case 5:
                    for(ll i = 3; i < 6; i++) {
                        for(ll j = 6; j < 9; j++) {
                            candi[m[i][j]] = 0;
                        }
                    }
                    break;
                case 6:
                    for(ll i = 6; i < 9; i++) {
                        for(ll j = 0; j < 3; j++) {
                            candi[m[i][j]] = 0;
                        }
                    }
                    break;
                case 7:
                    for(ll i = 6; i < 9; i++) {
                        for(ll j = 3; j < 6; j++) {
                            candi[m[i][j]] = 0;
                        }
                    }
                    break;
                case 8:
                    for(ll i = 6; i < 9; i++) {
                        for(ll j = 6; j < 9; j++) {
                            candi[m[i][j]] = 0;
                        }
                    }
                    break;
            }
            
            for(ll i = 1; i <= 9; i++) {
                if(candi[i]) {
                    m[y][x] = i;
                    solve(pos + 1);
                    m[y][x] = 0;
                }
            }
        } else {
            solve(pos + 1);
        }
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        for(ll i = 0; i < 9; i++) {
            for(ll j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    m[i][j] = 0;
                } else {
                    m[i][j] = board[i][j] - '0';
                }
            }
        }
        
        solve(0);
        
        for(ll i = 0; i < 9; i++) {
            for(ll j = 0; j < 9; j++) {
                board[i][j] = ans[i][j];
            }
        }
    }
};