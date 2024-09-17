class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=INT_MIN;
        while(l<=r){
            ans=max(ans,min(nums[l],nums[r])*(r-l));
            if(nums[l]<nums[r])
                l++;
            else
                r--;
        }

        return ans;

    }
};