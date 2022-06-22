class Solution {
public:
    int partition (vector<int> &nums,int left,int right){
        int l=left+1;
        int r=right;
        int pivot=nums[left];
        while(l<=r){
            if(nums[l]<pivot && nums[r]>pivot){
                swap(nums[l++],nums[r--]);
            }
            
            else{
                if(nums[l]>=pivot){
                    l++;
                }
                else if(nums[r]<=pivot)
                    r--;
            }
        }
        
        swap(nums[left],nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int left=0;
        int right=nums.size()-1;
        int ans;
        
        while(1){
            int pivotIndex=partition(nums,left,right);
            
            if(pivotIndex==k-1){
                ans= nums[pivotIndex];
                break;
            }
            
            else if (pivotIndex>k-1){
                right=pivotIndex-1;
            }
            else{
                left=pivotIndex+1;
            }
        }
        return ans;
    }
};