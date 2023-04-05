class Solution {
public:
    
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