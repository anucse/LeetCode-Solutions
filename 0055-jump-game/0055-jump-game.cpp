class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        vector<bool> dp(n,false);
        dp[n-1]=true;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=nums[i];j++){
                if(i+j<=n-1 && dp[i+j])
                {
                    dp[i]=true;
                    break;
                }
            }
            
        }
        
        return dp[0];
    }
};