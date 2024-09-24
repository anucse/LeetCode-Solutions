class Solution {
public:
    int solve(vector<vector<int>>& dp, int m,int n, int i, int j){
        
        if(i>=m || j>=n){
            return 0;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        dp[i][j]=solve(dp,m,n,i-1,j)+solve(dp,m,n,i,j-1);
        return dp[i][j];

    }
    int uniquePaths(int m, int n) {
        if(m==1 || n==1){
            return 1;
        }
        vector<vector<int>> dp(m,vector<int> (n,-1));
        dp[0][0]=0;
        dp[0][1]=1;
        dp[1][0]=1;
        return solve(dp,m,n,m-1,n-1);
    }
};