class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        vector<vector<int>> dp(n,vector<int> (amount+1,1e9));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0){
                    if(j%coins[0]==0)
                        dp[i][j]=j/coins[0];
                    else
                        dp[i][j]=1e9;
                }
                else{
                    int t=1e9;
                    if(j>=coins[i])
                        t=dp[i][j-coins[i]]+1;
                    int nt=dp[i-1][j];
                    dp[i][j]=min(t,nt);
                }
            }
        }
        
        int ans=dp[n-1][amount];
        return ans==1e9?-1:ans;
    }
};