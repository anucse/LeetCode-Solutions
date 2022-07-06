class Solution {
public:
    int solve(vector<int>& nums, int n,int i){
        vector<int> dp(n,INT_MIN);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> nums1,nums2;
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        
        
        for(int i=0;i<nums.size();i++){
            if(i!=0)
                nums1.push_back(nums[i]);
            if(i!=n-1)
                nums2.push_back(nums[i]);
        }
        
        return max(solve(nums1,n-1,0),solve(nums2,n-1,0));
    }
};