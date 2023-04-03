class Solution {
public:
    
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n,INT_MIN);
        if(n==1)
            return nums[0];
        
        int prev2=nums[0];
        int prev1;
        if(n>1)
            prev1=max(nums[0],nums[1]);
        
        int ans=prev1;
        
        for(int i=2;i<n;i++){
            ans=max(nums[i]+prev2,prev1);
            prev2=prev1;
            prev1=ans;
        }
        
        return ans;
    }
};