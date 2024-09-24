class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        for(int j=0;j<n;j++){
            dp[0][j]=grid[0][j];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+grid[i][j];
                }
                else if(j==n-1){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+grid[i][j];
                }
                else{
                    dp[i][j]=min(dp[i-1][j],min(dp[i-1][j+1],dp[i-1][j-1]))+grid[i][j];
                }
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,dp[m-1][j]);
        }

        return ans;
    }
};