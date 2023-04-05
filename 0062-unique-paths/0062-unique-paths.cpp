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
        
        vector<vector<int>> dp(m,vector<int> (n,0));
        
        
        for(int i=0;i<m;i++){
            dp[i][n-1]=1;
        }
        
        for(int j=0;j<n;j++){
            dp[m-1][j]=1;
        }
        
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                int right=dp[i][j+1];
                int down= dp[i+1][j];

                dp[i][j]=right+down;
            }
        }
        
        return dp[0][0];
    }
};