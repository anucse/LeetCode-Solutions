class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0;
        int best_buy=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>best_buy){
                int profit=prices[i]-best_buy;
                mx=max(mx,profit);
            }
            best_buy=min(best_buy,prices[i]);
        }

        return mx;
    }
};