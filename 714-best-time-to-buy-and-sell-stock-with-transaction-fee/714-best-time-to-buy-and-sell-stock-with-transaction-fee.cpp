class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& prices,int i,bool allowedToBuy,int fee){
        if(i>=prices.size())
            return 0;
        if(dp[i][allowedToBuy]!=-1)
            return dp[i][allowedToBuy];
        
        int doNothing=solve(prices,i+1,allowedToBuy,fee);
        if(allowedToBuy){
            int buy=solve(prices,i+1,!allowedToBuy,fee)-prices[i];
            dp[i][allowedToBuy]=max(buy,doNothing);
        }
        else{
            int sell=solve(prices,i+1,!allowedToBuy,fee)+prices[i]-fee;
            dp[i][allowedToBuy]=max(sell,doNothing);
        }
        
        return dp[i][allowedToBuy];
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return solve(prices,0,true,fee);
    }
};