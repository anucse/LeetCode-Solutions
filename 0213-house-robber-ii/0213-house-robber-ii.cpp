class Solution {
public:
    int solve(vector<int> &nums,int n){
        
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        int ans;
        
        for(int i=2;i<n;i++){
            ans=max(nums[i]+prev2,prev1);
            prev2=prev1;
            prev1=ans;
        }
        
        return prev1;
    }
    
    
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        
        
        vector<int> nums1(nums.begin(),nums.end()-1);
        vector<int> nums2(nums.begin()+1,nums.end());
        
        
        
        return max(solve(nums1,n-1),solve(nums2,n-1));
    }
};