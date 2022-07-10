class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        
        if(n==1)
            return cost[0];
        
        int prev2=cost[0];
        int prev1=cost[1];
        
        int ans=min(prev1,prev2);
        
        for(int i=2;i<n;i++){
            ans=min(prev1,prev2)+cost[i];
            prev2=prev1;
            prev1=ans;
        }
        
        return min(prev1,prev2);
    }
};