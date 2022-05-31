class Solution {
public:
    int ans;
    int search(vector<int>& nums, int target){
        int n=nums.size();
        b_search(nums,target,0,n-1);
        return ans;
    }
    
    void b_search(vector<int>& nums, int target,int left,int right) {
        if(left>right){
            ans=-1;
            return ;
        }
            
        int mid=(left+right)/2;
        if(target==nums[mid])
            ans= mid;
        else if(target<nums[mid])
            b_search(nums,target,left,mid-1);
        else{
            b_search(nums,target,mid+1,right);
        }
        
    }
};