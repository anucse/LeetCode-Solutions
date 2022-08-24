class Solution {
public:
    int solve(vector<int>& prices,int n,int fee, int i,bool allowedToBuy){
        if(i>=n)
            return 0;
        
        int wait=solve(prices,n,fee,i+1,allowedToBuy);
        
        if(allowedToBuy){
            int buy=solve(prices,n,fee,i+1,!allowedToBuy)-prices[i];
            return max(buy,wait);
        }
        else{
            int sell=solve(prices,n,fee,i+1,!allowedToBuy)+prices[i]-fee;
            return max(sell,wait);
        }
        
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        
        for(int i=n-1;i>=0;i--){
            for(int allowedToBuy=0;allowedToBuy<2;allowedToBuy++){
                //int profit=0;
                if(allowedToBuy){
                    int buy=dp[i+1][0]-prices[i];
                    int wait=dp[i+1][1];
                    dp[i][allowedToBuy]=max(buy,wait);
                }
                else{
                    int sell=dp[i+1][1]+prices[i]-fee;
                    int wait=dp[i+1][0];
                    dp[i][allowedToBuy]=max(sell,wait);
                }
                //dp[i][allowedToBuy]=profit;
            }
        }
        return dp[0][1];
    }
};