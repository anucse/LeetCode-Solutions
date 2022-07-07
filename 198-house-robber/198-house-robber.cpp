class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        
        int ans;
        
        for(int i=2;i<n;i++){
            ans=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=ans;
        }
        
        return ans;
    }
};