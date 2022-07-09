class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minimum=INT_MAX;
        int profit=0;
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            minimum=min(minimum,prices[i]);
            profit=(prices[i]-minimum);
            ans=max(ans,profit);
        }
        
        return ans;
    }
};