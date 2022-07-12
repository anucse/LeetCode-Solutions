class Solution {
public:
    int const inf=1e8;
    int solve(vector<vector<int>>& matrix,vector<vector<int>>& dp, int r,int c,int i,int j){
        if(j<0 || j>=c)
            return inf;
        if(i==r-1)
            return matrix[r-1][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int down=solve(matrix,dp, r,c,i+1,j)+matrix[i][j];
        int left=solve(matrix,dp, r,c,i+1,j-1)+matrix[i][j];
        int right=solve(matrix,dp, r,c,i+1,j+1)+matrix[i][j];
        
        return dp[i][j]=min({down,left,right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        
        vector<vector<int>> dp(r,vector<int>(c,-1));
        
        int ans=INT_MAX;
        
        for(int i=0;i<c;i++){
            ans=min(ans,solve(matrix,dp,r,c,0,i));
        }
        
        return ans;
    }
};