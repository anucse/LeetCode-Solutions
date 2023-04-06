class Solution {
public:
    int minDistance(string s1, string s2) {
        
        int m=s1.size();
        int n=s2.size();
        
        vector<vector<int>> dp(m+1, vector<int> (n+1,0));
        
        for(int i=0;i<=m;i++){
            dp[i][0]=i;
        }
        
        for(int j=0;j<=n;j++){
            dp[0][j]=j;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int replace=dp[i-1][j-1]+1;
                    int insert=dp[i][j-1]+1;
                    int del=dp[i-1][j]+1;
                    
                    dp[i][j]=min(replace,min(insert,del));
                }
            }
        }
        return dp[m][n];
    }
};