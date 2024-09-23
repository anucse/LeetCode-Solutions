class Solution {
public:
vector<int> dp;
    int solve(vector<int>& cost, int n, int i){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=INT_MAX)
            return dp[i];
        int min_cost=INT_MAX;
        min_cost=min(cost[i]+solve(cost,n,i+1),cost[i]+solve(cost,n,i+2));
        dp[i]=min_cost;
        return min_cost;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.resize(n+1,INT_MAX);
        return min(solve(cost,n,0),solve(cost,n,1));
    }
};