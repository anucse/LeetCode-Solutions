class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int m,int n, int i,int j){
        if(i>=m || j>=n)
            return 0;
        if(nums1[i]==nums2[j])
            return 1+solve(nums1,nums2,m,n,i+1,j+1);
        return max(solve(nums1,nums2,m,n,i+1,j),solve(nums1,nums2,m,n,i,j+1));
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<vector<int>> dp(m,vector<int> (m,0));
        
        for(int i=0;i<m;i++){
            if(nums2[n-1]==nums1[i])
                dp[i][n-1]=1;
        }
        
        for(int j=0;j<n;j++){
            if(nums2[j]==nums1[m-1])
                dp[m-1][j]=1;
        }
        int ans=0;
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(nums1[i]==nums2[j])
                    dp[i][j]=1+dp[i+1][j+1];
                ans=max(ans,dp[i][j]);
                
            }
        }
        return ans;
        
    }
};