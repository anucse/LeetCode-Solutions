class Solution {
public:
    int longestCommonSubsequence(string s1, string s2, int n1, int n2){
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else{
                    if(s1[i-1]==s2[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n1][n2];
        
    }
    
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string s2=s;
        reverse(s2.begin(),s2.end());
        return longestCommonSubsequence(s,s2,n,n);
    }
};