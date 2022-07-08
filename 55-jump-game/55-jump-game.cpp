class Solution {
public:
    bool solve(vector<int>& nums,vector<int>& dp, int n,int i){
        if(i==n-1)
            return true;
        if(i>=n)
            return false ;
        if(dp[i]!=-1)
            return dp[i];
        for(int j=i+1;j<=i+nums[i];j++){
            bool ans=solve(nums,dp,n,j);
            if(ans){
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,dp,n,0);
    }
};