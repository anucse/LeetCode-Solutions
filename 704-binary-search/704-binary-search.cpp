class Solution {
private:
    int ans=-1;
public:
    void solve(vector<int>& nums,int target, int left,int right){
        int mid=(left+right)/2;
        
        if(left>right)
            return;
        
        if(nums[mid]==target){
            ans=mid;
            return;
        }
        
        else if(nums[mid]>target){
            solve(nums,target, left,mid-1);
        }
        
        else{
            solve(nums,target, mid+1,right);
        }
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        solve(nums,target, 0,n-1);
        return ans;
    }
};