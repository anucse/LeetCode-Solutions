class Solution {
public:
    int dp[51][51][51];
    int const mod=1e9+7;
    
    int solve(int r, int c, int maxMove, int i, int j){
        if(maxMove<0)
            return 0;
        if(i>=r || j>=c || i<0 || j<0)
            return 1;
        
        
        if(dp[maxMove][i][j]!=-1)
            return dp[maxMove][i][j];
        
        int ans=0;
        
        
        ans+=(solve(r,c,maxMove-1,i-1,j)%mod);
        ans%=mod;
        ans+=(solve(r,c,maxMove-1,i,j-1)%mod);
        ans%=mod;
        ans+=(solve(r,c,maxMove-1,i+1,j)%mod);
        ans%=mod;
        ans+=(solve(r,c,maxMove-1,i,j+1)%mod);
        ans%=mod;
        
        return dp[maxMove][i][j] = ans%mod;
    }
    int findPaths(int r, int c, int maxMove, int sr, int sc) {
        //vector<vector<int>> dp(r,vector<int> (c,-1)); 
        memset(dp,-1,sizeof(dp));
        return solve(r,c,maxMove,sr,sc);
    }
};