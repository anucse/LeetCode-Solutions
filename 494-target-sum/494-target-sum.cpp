class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>> dp(nums.size());
        return solve(nums,dp,target,nums.size()-1,0);
    }
    
    int solve(vector<int>& nums,vector<unordered_map<int,int>> &dp,int target,int i,int sum){
        if(i<0){
            if(sum==target)
                return 1;
            else
                return 0;
        }
        
        auto it=dp[i].find(sum);
        
        if(it != dp[i].end())
            return dp[i][sum];
        
        return dp[i][sum]=solve(nums,dp,target,i-1,sum+nums[i])+solve(nums,dp,target,i-1,sum-nums[i]);
    }
};