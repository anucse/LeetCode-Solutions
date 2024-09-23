class Solution {
public:
vector<int> dp;
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.resize(n+1,INT_MAX);
        //return min(solve(cost,n,0),solve(cost,n,1));
        if(n==0){
            return 0;
        }
        if(n==1){
            return 0;
        }
        if(n==2){
            return min(cost[0],cost[1]);
        }
        dp[0]=cost[0];
        dp[1]=cost[1];
        dp[2]=min(dp[0],dp[1])+cost[2];
        for(int i=3;i<n;i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];

        }
        return min(dp[n-1],dp[n-2]);
    }
};