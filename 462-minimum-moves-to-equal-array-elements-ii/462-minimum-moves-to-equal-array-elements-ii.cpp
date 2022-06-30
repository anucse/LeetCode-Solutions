class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int medianIndex = (nums.size()-1)/2;
        int median = nums[medianIndex];
        int ans=0;
        
        
        for(int x:nums){
            ans+=abs(x-median);
        }
        
        return ans;
    }
};