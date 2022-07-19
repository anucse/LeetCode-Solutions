class Solution {
public:
    int solve(vector<vector<int>>& triangle,vector<vector<int>>& dp, int n, int i,int j){
        if(i>=n)
            return 0;
        if(j>i)
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down=solve(triangle,dp,n,i+1,j);
        int downRight=solve(triangle,dp,n,i+1,j+1);
        
        return dp[i][j]= min(down,downRight)+triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(triangle,dp,n,0,0);
    }
};