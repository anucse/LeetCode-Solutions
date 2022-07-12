class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& prices,int i,int allowedToBuy){
        if(i>=prices.size())
            return 0;
        if(dp[i][allowedToBuy]!=-1)
            return dp[i][allowedToBuy];
        
        int cooldown=solve(prices,i+1,allowedToBuy);
        
        if(allowedToBuy){
            int buy=solve(prices,i+1,!allowedToBuy)-prices[i];
            dp[i][allowedToBuy]=max(cooldown,buy);
        }
        else{
            int sell=solve(prices,i+2,!allowedToBuy)+prices[i];
            dp[i][allowedToBuy]=max(sell,cooldown);
        }
        
        return dp[i][allowedToBuy];
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return solve(prices,0,true);
    }
};