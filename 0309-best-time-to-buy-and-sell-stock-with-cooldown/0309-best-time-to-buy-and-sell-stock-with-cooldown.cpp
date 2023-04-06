class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<int> prev2(2,0),prev1(2,0),curr(2,0);
        
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(!j){
                    curr[j]=max(prev1[1]-prices[i],prev1[0]);
                }
                else{
                    curr[j]=max(prev2[0]+prices[i],prev1[1]);
                }
            }
            prev2=prev1;
            prev1=curr;
        }
        
        return curr[0];
        
    }
};