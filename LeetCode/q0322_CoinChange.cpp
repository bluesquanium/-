#define ll long long

class Solution {
public:
    ll mem[10001];
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        for(ll i = 0; i <= amount; i++) {
            mem[i] = 9999999;
        }
        mem[0] = 0;
        for(ll i = 0; i< coins.size(); i++) {
            if(coins[i] > 10000) {
                continue;
            }
            mem[coins[i]] = 1;
        }
        for(ll i = coins[0]; i <= amount; i++) {
            for(ll j = 0; j < coins.size(); j++) {
                if(i - coins[j] >= 0) {
                    mem[i] = min(mem[i], mem[i- coins[j]] + 1);   
                }
            }
        }
        
        return mem[amount] >= 9999999 ? -1 : mem[amount];
    }
};