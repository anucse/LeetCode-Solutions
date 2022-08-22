class Solution {
public:
    int solve(int r,int c,int i,int j){
        if(i==r-1 && j==c-1)
            return 1;
        if(i>=r || j>=c || i<0 || j<0)
            return 0;
        return solve(r,c,i+1,j)+solve(r,c,i,j+1);
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        
        for(int i=0;i<m;i++){
            dp[i][n-1]=1;
        }
        for(int j=0;j<n;j++){
            dp[m-1][j]=1;
        }
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        
        return dp[0][0];
    }
};