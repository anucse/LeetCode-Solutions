class Solution {
public:
    int minimumTotal(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        dp[0][0]=matrix[0][0];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==0){
                    dp[i][j]=dp[i-1][j]+matrix[i][j];
                }
                
                else{
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+matrix[i][j];
                }
            }
        }
        
        for(int j=0;j<n;j++){
            ans=min(ans,dp[n-1][j]);
        }
        
        return ans;
    }
};