class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k<=1)
            return 0;
        
        int n=nums.size();
        int prod=1;
        int ans=0;
        int left=0;
        int right;
        for(right=0;right<n;right++){
            prod*=nums[right];
            while(prod>=k){
                prod/=nums[left];
                left++;
            }
            
            ans+=(right-left+1);
        }
        
        return ans;
    }
    
};