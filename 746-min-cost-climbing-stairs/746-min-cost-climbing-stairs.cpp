class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        
        
        
        
        int prev2=0;
        int prev1=min(cost[0],cost[1]);
        
        int ans=prev1;
        
        for(int i=3;i<=n;i++){
            ans=min(prev1+cost[i-1],prev2+cost[i-2]);
            prev2=prev1;
            prev1=ans;
        }
        
        return ans;
    }
};