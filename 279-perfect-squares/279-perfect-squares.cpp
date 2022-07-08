class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        
        int ans=INT_MAX;
        
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solve(n-i*i,dp));
        }
        return dp[n]=ans;
    }
    
    
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        
        return dp[n];
    }
};