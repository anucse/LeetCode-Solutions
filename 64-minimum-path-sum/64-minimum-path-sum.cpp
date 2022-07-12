class Solution {
public:
    int solve(vector<vector<int>>& grid,vector<vector<int>>& dp, int r,int c,int i,int j){
        if(i<0 || j<0)
            return 1e9;
        if(i==0 && j==0)
            return grid[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int up=solve(grid,dp,r,c,i-1,j);
        int left=solve(grid,dp,r,c,i,j-1);
        
        return dp[i][j]=min(up,left)+grid[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> dp(r,vector<int> (c,-1));
        return solve(grid,dp, r,c,r-1,c-1);
    }
};