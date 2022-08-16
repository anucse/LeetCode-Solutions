class Solution {
public:
    int solve(vector<int> &count,vector<int> &dp,int i){
        if(i>=10001)
            return 0; //1-10000
        
        if(dp[i]!=-1)
            return dp[i];
        
        int take=solve(count,dp,i+2)+count[i]*i;
        int not_take=solve(count,dp,i+1);
        
        return dp[i]= max(take,not_take);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int> count(10001,0);
        
        for(int x:nums){
            count[x]++;
        }
        
        vector<int> dp(10001,-1);
        
        return solve(count,dp,1);
        
    }
};