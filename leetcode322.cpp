//属于完全背包问题，直接套模板
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount+1, 100000000);
        f[0] = 0;
        for(int i=0;i<coins.size(); i++) {
            for(int m= coins[i]; m<=amount; m++) {
                f[m] = min(f[m], f[m-coins[i]]+1);
            }
        }
        if(f[amount] == 100000000) f[amount] = -1;
        return f[amount];
    }
};