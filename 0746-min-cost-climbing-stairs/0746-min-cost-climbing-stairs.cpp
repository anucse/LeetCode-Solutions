class Solution {
public:
    int solve(vector<int> &cost,int n,int i){
        
        if(i>=n)
            return 0;
        
        int opt1=solve(cost,n,i+1)+cost[i];
        int opt2=solve(cost,n,i+2)+cost[i];
        
        return min(opt1,opt2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        
        vector<int> dp(n+2,INT_MAX);
        dp[n]=0;
        dp[n+1]=0;
        for(int i=n-1;i>=0;i--){
            int opt1=dp[i+1]+cost[i];
            int opt2=dp[i+2]+cost[i];

            dp[i]= min(opt1,opt2);
        }
        
        return min(dp[0],dp[1]);
    }
};