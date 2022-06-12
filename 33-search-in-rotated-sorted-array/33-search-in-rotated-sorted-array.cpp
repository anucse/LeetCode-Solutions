class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int n=nums.size();
        int r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target)
                return mid;
            
            // if left part is sorted
            if(nums[l]<=nums[mid]){
                if(target>=nums[l] && target<=nums[mid]){
                    r=mid-1;
                }
                else 
                    l=mid+1;
            }
            
            // if left part is not sorted , right part must be sorted
            else{
                if(target>=nums[mid] && target<=nums[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        return -1;
    }
};