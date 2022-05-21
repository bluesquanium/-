#define ll int

class Solution {
public:
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
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;
        for(ll y = 0; y < 9; y++) {
            for(ll x = 0; x < 9; x++) {
                if(board[y][x] == '.') continue;
                
                char cur = board[y][x];
                
                for(ll i = 0; i < 9; i++) {
                    if(i == y) continue;
                    if(board[i][x] == cur) {
                        ans = false;
                        break;
                    }
                }
                for(ll j = 0; j < 9; j++) {
                    if(j == x) continue;
                    if(board[y][j] == cur) {
                        ans = false;
                        break;
                    }
                }
                
                ll curCase = cases[y][x];
                switch(curCase) {
                    case 0:
                        for(ll i = 0; i < 3; i++) {
                            for(ll j = 0; j < 3; j++) {
                                if(board[i][j] == cur) {
                                    if(y == i && x == j) continue;
                                    ans = false;
                                    break;
                                }
                            }
                        }
                        break;
                    case 1:
                        for(ll i = 0; i < 3; i++) {
                            for(ll j = 3; j < 6; j++) {
                                if(board[i][j] == cur) {
                                    if(y == i && x == j) continue;
                                    ans =false;
                                    break;
                                }
                            }
                        }
                        break;
                    case 2:
                        for(ll i = 0; i < 3; i++) {
                            for(ll j = 6; j < 9; j++) {
                                if(board[i][j] == cur) {
                                    if(y == i && x == j) continue;
                                    ans =false;
                                    break;
                                }
                            }
                        }
                        break;
                    case 3:
                        for(ll i = 3; i < 6; i++) {
                            for(ll j = 0; j < 3; j++) {
                                if(board[i][j] == cur) {
                                    if(y == i && x == j) continue;
                                    ans =false;
                                    break;
                                }
                            }
                        }
                        break;
                    case 4:
                        for(ll i = 3; i < 6; i++) {
                            for(ll j = 3; j < 6; j++) {
                                if(board[i][j] == cur) {
                                    if(y == i && x == j) continue;
                                    ans =false;
                                    break;
                                }
                            }
                        }
                        break;
                    case 5:
                        for(ll i = 3; i < 6; i++) {
                            for(ll j = 6; j < 9; j++) {
                                if(board[i][j] == cur) {
                                    if(y == i && x == j) continue;
                                    ans =false;
                                    break;
                                }
                            }
                        }
                        break;
                    case 6:
                        for(ll i = 6; i < 9; i++) {
                            for(ll j = 0; j < 3; j++) {
                                if(board[i][j] == cur) {
                                    if(y == i && x == j) continue;
                                    ans =false;
                                    break;
                                }
                            }
                        }
                        break;
                    case 7:
                        for(ll i = 6; i < 9; i++) {
                            for(ll j = 3; j < 6; j++) {
                                if(board[i][j] == cur) {
                                    if(y == i && x == j) continue;
                                    ans =false;
                                    break;
                                }
                            }
                        }
                        break;
                    case 8:
                        for(ll i = 6; i < 9; i++) {
                            for(ll j = 6; j < 9; j++) {
                                if(board[i][j] == cur) {
                                    if(y == i && x == j) continue;
                                    ans =false;
                                    break;
                                }
                            }
                        }
                        break;
                }
            }
        }
        
        return ans;
    }
};