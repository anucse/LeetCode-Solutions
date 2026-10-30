class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //vector<int> dp(n, INT_MIN);
        if (n==1)
        return nums[0];
        if (n==2)
        return max(nums[0],nums[1]);
        //dp[0]=nums[0];
        int prev1=nums[0];
        //dp[1]=max(nums[0],nums[1]);
        int prev2=max(nums[0],nums[1]);
        int curr=INT_MIN;
        for (int i=2;i<n;i++){
           curr=max((prev1+nums[i]),(prev2));
           prev1=prev2;
           prev2=curr;
           
        }

        return curr;
    }
};