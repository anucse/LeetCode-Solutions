class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int minimum=prices[0];
        int ans=INT_MIN;
        
        for(int i=1;i<n;i++){
            
            int profit=prices[i]-minimum;
            minimum=min(minimum,prices[i]);
            ans=max(ans,profit);
        }
        
        return ans<0?0:ans;
    }
};