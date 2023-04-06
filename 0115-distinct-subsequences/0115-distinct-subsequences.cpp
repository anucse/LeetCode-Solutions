class Solution {
public:
    vector<vector<int>> dp;
    int solve(string s, string t, int m, int n, int i, int j){
        if(j>=n)
            return 1;
        if(i>=m)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j]=solve(s,t,m,n,i+1,j+1)+solve(s,t,m,n,i+1,j);
        
        return dp[i][j]=solve(s,t,m,n,i+1,j);
    }
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        dp.resize(m,vector<int>(n,-1));
        return solve(s,t,m,n,0,0);
    }
};