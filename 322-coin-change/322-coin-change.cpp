class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int curr_amount=1;curr_amount<=amount;curr_amount++){
            for(int coin :coins){
                if(coin<=curr_amount){
                    dp[curr_amount]=min(dp[curr_amount],1+dp[curr_amount-coin]);
                }
            }
        }
        return (dp[amount]==amount+1)?-1:dp[amount];
    }
};