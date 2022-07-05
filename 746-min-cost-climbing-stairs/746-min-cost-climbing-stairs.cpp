class Solution {
public:
    int solve(vector<int>& cost,int n,vector<int>& dp){
        if(n<0)
            return 0;
        if(n==0 || n==1)
            return cost[n];
        if(dp[n]!=INT_MAX)
            return dp[n];
        dp[n]= cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return dp[n];
    }
    
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        
        vector<int> dp(n+1,INT_MAX);
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        
        return min(dp[n-2],dp[n-1]);
    }
};