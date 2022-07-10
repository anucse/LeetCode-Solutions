class Solution {
public:
    int solve(vector<int>& cost,vector<int>& dp, int n, int i){
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=min(solve(cost,dp,n,i+1)+cost[i],solve(cost,dp,n,i+2)+cost[i]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==1)
            return cost[0];
        vector<int> dp(cost.size(),-1);
        return min(solve(cost,dp,cost.size(),0),solve(cost,dp,cost.size(),1));
    }
};