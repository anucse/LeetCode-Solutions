class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        if(k==0||prices.size()==0||prices.size()==1)
            return 0;
        int n=prices.size();
        vector<vector<int>> dp(k+1,vector<int>(n));
        
        for(int i=0;i<k+1;i++){  // at most i tran, on j th day 
            for(int j=0;j<n;j++){
                if(i==0)
                    dp[i][j]=0;
                else if(j==0)
                    dp[i][j]=0;
                else{
                    int maxProfit=INT_MIN;
                    for(int p=0;p<j;p++){
                        int profit=prices[j]-prices[p]+dp[i-1][p];
                        maxProfit=max(maxProfit,profit);
                    }
                    dp[i][j]=max(dp[i][j-1],maxProfit);
                }
            }
        }
        
        return dp[k][n-1];
    }
};