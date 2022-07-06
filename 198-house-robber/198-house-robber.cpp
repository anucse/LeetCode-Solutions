class Solution {
public:
    int solve(vector<int>& nums,vector<int>& dp,int n,int i){
        if(i>=n)
            return 0;
        if(dp[i]!=INT_MIN)
            return dp[i];
        dp[i]= max(nums[i]+solve(nums,dp,n,i+2),solve(nums,dp,n,i+1));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MIN);
        return solve(nums,dp,n,0);
    }
};