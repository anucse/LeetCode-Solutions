class Solution {
public:
    int solve(vector<int>& coins,int target, vector<vector<int>> &dp,int n,int i){
        
        if(i>=n || target<0)
            return 0;
        if(target==0)
            return 1;
        if(dp[i][target]!=-1)
            return dp[i][target];
        int t=0;
        if(target>=coins[i])
            t=solve(coins,target-coins[i],dp,n,i);
        int nt=solve(coins,target,dp,n,i+1);
        
        return dp[i][target]=t+nt;
    }
    int change(int target, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        return solve(coins,target,dp,n,0);
    }
};