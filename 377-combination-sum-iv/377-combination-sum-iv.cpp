class Solution {
public:
    int solve(vector<int>& nums, int target,vector<int> &dp){
        if(target==0)
            return 1;
        if(target<0)
            return 0;
        if(dp[target]!=-1)
            return dp[target];
        
        dp[target]=0;
        for(int x:nums){
            dp[target]+=solve(nums,target-x,dp);
        }
        
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target+1,0);
        sort(nums.begin(),nums.end());
        dp[0]=1;
        for(int currTarget=1;currTarget<=target;currTarget++){
            for(int x:nums){
                if(x<=currTarget)
                    dp[currTarget]+=dp[currTarget-x];
                else
                    break;
            }
        }
        
        return dp[target];
        
    }
};