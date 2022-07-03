class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return  0;
        int increasing=1;
        int decreasing=1;
        
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i])
                increasing =decreasing+1;
            else if(nums[i]<nums[i-1])
                decreasing=increasing+1;
        }
        
        return max(increasing,decreasing);
    }
};