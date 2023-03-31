class Solution {
public:
   
    string longestPalindrome(string s) {
        
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        
        string ans="";
        ans+=s[0];
        
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(s[i]==s[j]){
                    if(i-j==1 || dp[i-1][j+1]){
                        dp[i][j]=1;
                        if(ans.size()<(i-j+1))
                            ans=s.substr(j,i-j+1);
                    }
                }
            }
        }
        
        return ans;
        
    }
};