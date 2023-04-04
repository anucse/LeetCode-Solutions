class Solution {
public:
    int solve(vector<int>& coins, int amount,vector<vector<int>> &dp, int n,int i){
        if(i==0){
            if(amount%coins[0]==0)
                return amount/coins[0];
            return 1e9;
        }
        if(dp[i][amount] !=-1)
            return dp[i][amount] ;
        
        int t=1e9;
        
        if(amount>=coins[i])
            t=1+solve(coins,amount-coins[i],dp,n,i);
        int nt=solve(coins,amount,dp,n,i-1);
        
        
        return dp[i][amount]=min(t,nt);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans=solve(coins,amount,dp, n,n-1);
        if(ans!=1e9)
            return ans;
        return -1;
    }
};