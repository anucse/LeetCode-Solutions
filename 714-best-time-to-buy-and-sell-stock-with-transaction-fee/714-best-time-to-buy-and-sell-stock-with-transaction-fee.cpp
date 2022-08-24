class Solution {
public:
    int solve(vector<int>& prices,int n,int fee, int i,bool allowedToBuy){
        if(i>=n)
            return 0;
        
        int wait=solve(prices,n,fee,i+1,allowedToBuy);
        
        if(allowedToBuy){
            int buy=solve(prices,n,fee,i+1,!allowedToBuy)-prices[i];
            return max(buy,wait);
        }
        else{
            int sell=solve(prices,n,fee,i+1,!allowedToBuy)+prices[i]-fee;
            return max(sell,wait);
        }
        
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        //vector<vector<int>> dp(n+1,vector<int> (2,0));
        vector<int> prev(2,0);
        vector<int> curr(2,0);
        
        for(int i=n-1;i>=0;i--){
            for(int allowedToBuy=0;allowedToBuy<2;allowedToBuy++){
                
                if(allowedToBuy){
                    int buy=prev[0]-prices[i];
                    int wait=prev[1];
                    curr[allowedToBuy]=max(buy,wait);
                }
                else{
                    int sell=prev[1]+prices[i]-fee;
                    int wait=prev[0];
                    curr[allowedToBuy]=max(sell,wait);
                }
                prev=curr;
            }
        }
        return prev[1];
    }
};