class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int target) {
        
        int n=nums.size();
        int l=0;
        int r=0;
        int prod =1;
        
        int ans=0;
        
        while(r<n){
            prod*=nums[r];
            
            while(prod>=target && l<=r){
                prod/=nums[l];
                l++;
                
            }
            ans+=(r-l+1);
            r++;
        }
        
        return ans;
    }
};