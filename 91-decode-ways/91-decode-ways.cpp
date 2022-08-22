class Solution {
public:
    
    int solve(string s,vector<int> dp,int n,int i){
        
        if(i>=n)
            return 1;
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        
        int ans=0;
        ans+=solve(s,dp,n,i+1);
        if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6')))
            ans+=solve(s,dp,n,i+2);
        
        return dp[i]=ans;
    }
    
    int numDecodings(string s) {
        int n=s.size();
        if(n==0)
            return 0;
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')
                dp[i]=0;
            else{
                dp[i]+=dp[i+1];
                if(i<n-1 && (s[i]=='1' ||(s[i]=='2' && s[i+1]<='6'))){
                    dp[i]+=dp[i+2];
                }
            }
        }
        return dp[0];
        
        
    }
};