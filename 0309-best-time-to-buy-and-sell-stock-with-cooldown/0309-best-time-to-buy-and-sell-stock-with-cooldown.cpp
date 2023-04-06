class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& prices,int n,int i,int stock){
        if(i>=n){
            return 0;
        }
        if(dp[i][stock]!=-1)
            return dp[i][stock];
        
        if(!stock){
            return dp[i][stock]=max(solve(prices,n,i+1,1)-prices[i],solve(prices,n,i+1,0));
        }
        else{
            return dp[i][stock]=max(solve(prices,n,i+2,0)+prices[i],solve(prices,n,i+1,1));
        }
        
    }
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        dp.resize(n+2,vector<int> (2,0));
        // return solve(prices,n,0,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(!j){
                    dp[i][j]=max(dp[i+1][1]-prices[i],dp[i+1][0]);
                }
                else{
                    dp[i][j]=max(dp[i+2][0]+prices[i],dp[i+1][1]);
                }
            }
        }
        
        return dp[0][0];
        
    }
};