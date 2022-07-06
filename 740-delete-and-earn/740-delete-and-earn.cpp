class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001,0); // 0-10000
        for(int x:nums){
            count[x]++;
        }
        
        vector<int> dp(10001,INT_MIN);
        
        dp[0]=count[0];
        dp[1]=max(count[0],count[1]);
        
        for(int i=2;i<=10000;i++){
            dp[i]=max(dp[i-1],(count[i]*i)+dp[i-2]);
        }
        
        return dp[10000];
    }
};