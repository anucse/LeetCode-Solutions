class Solution {
public:
    
    int solve(vector<int>& nums,vector<int>& dp,int i,int j){
        if(i>=j)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=max(solve(nums,dp,i+1,j),solve(nums,dp,i+2,j)+nums[i]);
    }
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        return max(solve(nums,dp1,1,nums.size()),solve(nums,dp2,0,nums.size()-1));
    }
};