class Solution {
public:
    
    int solve(vector<int>& nums, int n, int i, vector<int>& dp){
        
        if (i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];

        int currVal=nums[i];
        int nextIndex = i+1;
        int currSum=nums[i];

        while(nextIndex<n && nums[nextIndex]==currVal){
            currSum+=nums[i];
            nextIndex++;
        }

        while(nextIndex<n && nums[nextIndex]==currVal+1){
            nextIndex++;
        }

        return dp[i]=max((currSum+solve(nums, n, nextIndex, dp)), solve(nums,n,i+1, dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(20001,-1);
        return solve(nums,n, 0,dp);
    }
};