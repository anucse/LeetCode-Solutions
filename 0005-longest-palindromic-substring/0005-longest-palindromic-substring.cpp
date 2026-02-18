class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();

        if(len<=1)
            return s;
        vector<vector<bool>> dp(len,vector<bool>(len,false));

        int ans=1;
        int start=0;
        int end=0;

        for(int i=0;i<len;i++){
            for (int j=0;j<len;j++){
                if(i==j) dp[i][j]=true;
            }
        }

        for(int i=0;i<len;i++){
            for (int j=0;j<i;j++){
                //if(i==j) dp[i][j]=true;

                if(s[i]==s[j] && (dp[j+1][i-1]||i-j<=2)) {
                    dp[j][i]=true;
                    if(i-j+1>ans){
                        ans= i-j+1;
                        start=j;
                        end=i;
                    }
                }
            }
        }

        return s.substr(start,end-start+1);

    }
};