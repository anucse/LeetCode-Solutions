class Solution {
public:
    int solve(vector<int> &nums,int n){
        
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        
        int ans;
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            
            ans=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=ans;
        }
        
        return ans;
        
    }
    
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1)
            return nums[0];
        
        vector<int> nums1,nums2;
        
        for(int i=0;i<n;i++){
            if(i!=0)
                nums2.push_back(nums[i]);
            if(i!=n-1)
                nums1.push_back(nums[i]);
        }
        
        return max(solve(nums1,n-1),solve(nums2,n-1));
    }
};