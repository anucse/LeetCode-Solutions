class Solution {
public:
    int solve(vector<int> &nums,int target,int n,int i){
        
        vector<vector<int>> dp(n+1,vector<int> (target+1,0));
        if(nums[0]==0){
            dp[0][0]=2;  
        }
        else{
            dp[0][0]=1;
        }
        
        for(int i=1;i<n;i++){
            if(nums[i]==0)
                dp[i][0]=2*dp[i-1][0];
            else
                dp[i][0]=dp[i-1][0];
        }
        
        for(int j=1;j<=target;j++){
            if(nums[0]==j)
                dp[0][j]=1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                int t=0;
                if(j>=nums[i])
                    t=dp[i-1][j-nums[i]];
                
                int nt=dp[i-1][j];
                
                dp[i][j]=t+nt;
            }
        }
        
        return dp[n-1][target];
        
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n=nums.size();
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        if(sum<target)
            return 0;
        target=sum-target;
        if(target%2 !=0)
            return 0;
        target=target/2;
        return solve(nums,target,n,0);
    }
};