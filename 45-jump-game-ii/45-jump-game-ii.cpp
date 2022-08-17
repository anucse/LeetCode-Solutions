class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        if(n==2)
            return 1;
        vector<int> dp(n,10000);
        dp[n-1]=0;
        dp[n-2]=1;
        for(int i=n-3;i>=0;i--){
            for(int j=1;j<=nums[i];j++){
                if(i+j>=n)
                    continue;
                dp[i]=min(dp[i],dp[i+j]+1);
            }
        }
        return dp[0];
    }
};