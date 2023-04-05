class Solution {
public:
    int solve(int m,int n, vector<vector<int>>& dp, int i, int j){
        
        if(i==m-1 && j==n-1)
            return 1;
        
        if(i<0 || j<0 || i>=m || j>=n )
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int right=solve(m,n,dp,i,j+1);
        int down= solve(m,n,dp, i+1,j);
        
        return dp[i][j]=right+down;
        
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(m,n,dp,0,0);
    }
};