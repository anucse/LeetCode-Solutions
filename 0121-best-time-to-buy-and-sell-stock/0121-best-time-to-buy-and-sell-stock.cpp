class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini=INT_MAX;
        int profit=INT_MIN;
        int n=prices.size();
        
        for(int i=0;i<n;i++){
            mini=min(prices[i],mini);
            
            profit=max(profit,prices[i]-mini);
            
        }
        
        return profit;
    }
};