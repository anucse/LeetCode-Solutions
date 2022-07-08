class Solution {
public:
    int solve(vector<int>& nums,vector<int>& dp, int n,int i){
        if(i==n-1)
            return 0;
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=10000;
        for(int j=i+1;j<=i+nums[i];j++){
            ans=min(ans,solve(nums,dp,n,j)+1);
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,dp,n,0);
    }
};