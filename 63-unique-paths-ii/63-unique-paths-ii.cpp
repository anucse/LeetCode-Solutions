class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<long>> dp(r,vector<long> (c,0));
        for(int i=r-1;i>=0;i--){
            if(grid[i][c-1]==1)
                break;
            dp[i][c-1]=1;
        }
        for(int j=c-1;j>=0;j--){
            if(grid[r-1][j]==1)
                break;
            dp[r-1][j]=1;
        }
        
        for(int i=r-2;i>=0;i--){
            for(int j=c-2;j>=0;j--){
                if(grid[i][j]==1)
                    dp[i][j]=0;
                else{
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
                }
            }
        }
        
        return dp[0][0];
    }
};