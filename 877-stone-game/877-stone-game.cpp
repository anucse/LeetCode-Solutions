class Solution {
public:
    
    int solve(vector<int>& piles,vector<vector<int>> &dp, int l,int r){
        
        if(l==r-1){
            return max(piles[l],piles[r]);
        }
        
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        int pickLeft=piles[l]+max(solve(piles,dp,l+2,r),solve(piles,dp,l+1,r-1));
        int pickRight=piles[r]+max(solve(piles,dp,l,r-2),solve(piles,dp,l+1,r-1));
        
        return dp[l][r]=max(pickLeft,pickRight);
    }
    
    
    bool stoneGame(vector<int>& piles) {
        
        int n=piles.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        int alex=solve(piles,dp,0,n-1);
        
        int total=0;
        
        for(int x:piles){
            total+=x;
        }
        
        return alex>(total-alex);
    }
};