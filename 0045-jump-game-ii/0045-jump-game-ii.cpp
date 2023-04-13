class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,n-1);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int low=1e9;
            for(int j=i+1;j<=min(n-1,nums[i]+i) ;j++){
                low=min(low,dp[j]);
            }
            dp[i]=low+1;
        }
        
        return dp[0];
    }
};