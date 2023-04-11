class Solution {
public:
    int solve(vector<int>& nums, int n,vector<int> &dp, int i){
        if(i>=n-1){
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        int minJump=n;
        for(int j=i+1;j<=i+nums[i];j++){
            minJump=min(minJump,1+solve(nums,n,dp,j));
        }
        
        return dp[i]=minJump;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,nums.size(),dp,0);
    }
};