class Solution {
public:
    
    int change(int target, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (target+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=target;j++){
                if(j==0){
                    dp[i][j]=1;
                }
                else{
                    int t=0;
                    if(j>=coins[i])
                        t=dp[i][j-coins[i]];
                    int nt=dp[i+1][j];

                    dp[i][j]=t+nt;
                }
            }
        }
        return dp[0][target];
        
    }
};