class Solution {
public:
    int getMaximumGenerated(int n) {
        
        vector<int> dp(n+1,0);
        if(n==0)
            return 0;
        dp[1]=1;
        int ans=1;
        
        for(int i=2;i<=n;i++){
            if(i&1){
                dp[i]=dp[(i-1)>>1]+dp[((i-1)>>1)+1];
            }
            else{
                dp[i]=dp[(i>>1)];
            }
            ans=max(ans,dp[i]);
        }
        return ans;                  
    }
};