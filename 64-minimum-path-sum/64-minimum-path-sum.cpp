class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> dp(r,vector<int>(c,INT_MAX));
        dp[r-1][c-1]=grid[r-1][c-1];
        for(int j=c-2;j>=0;j--){
            dp[r-1][j]=dp[r-1][j+1]+grid[r-1][j];
        }
        for(int i=r-2;i>=0;i--){
            dp[i][c-1]=dp[i+1][c-1]+grid[i][c-1];
        }
        
        for(int i=r-2;i>=0;i--){
            for(int j=c-2;j>=0;j--){
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+grid[i][j];
            }
        }
        return dp[0][0];
    }
};