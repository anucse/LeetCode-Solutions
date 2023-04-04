class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        //vector<vector<int>> dp(n,vector<int> (amount+1,1e9));
        //dp[i-1]->prev
        //dp[i] -> curr
        vector<int> prev(amount+1,1e9);
        vector<int> curr(amount+1,1e9);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0){
                    if(j%coins[0]==0)
                        curr[j]=j/coins[0];
                    else
                        curr[j]=1e9;
                }
                else{
                    int t=1e9;
                    if(j>=coins[i])
                        t=curr[j-coins[i]]+1;
                    int nt=prev[j];
                    curr[j]=min(t,nt);
                }
            }
            prev=curr;
        }
        
        int ans=curr[amount];
        return ans==1e9?-1:ans;
    }
};