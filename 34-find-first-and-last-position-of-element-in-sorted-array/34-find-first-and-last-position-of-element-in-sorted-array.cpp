class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]>target){
                r=m-1;
                
            }
            else if(nums[m]<target){
                l=m+1;
            }
            
            else{
                if(m==l || nums[m]!=nums[m-1]){
                    ans[0]=m;
                    break;
                }
                
                else{
                    r=m-1;
                    ans[0]=m-1;
                }
            }
        }
        
        l=0;
        r=n-1;
        
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]>target){
                r=m-1;
                
            }
            else if(nums[m]<target){
                l=m+1;
            }
            
            else{
                if(m==r || nums[m]!=nums[m+1]){
                    ans[1]=m;
                    break;
                }
                
                else{
                    l=m+1;
                    ans[1]=m+1;
                }
            }
        }
        
        return ans;
    }
};