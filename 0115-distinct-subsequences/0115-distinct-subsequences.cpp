class Solution {
public:
    
    
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        // vector<vector<int>> dp;
        // dp.resize(m+1,vector<int>(n+1,0));
        // return solve(s,t,m,n,0,0);
        
        vector<unsigned long long> prev(n+1,0);
        vector<unsigned long long> curr(n+1,0);
        
        // for(int i=0;i<m;i++){
        //     dp[i][0]=1;
        // }
        
        for(int i=1;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(j==0)
                    prev[0]=1;
                else{
                    if(s[i-1]==t[j-1]){
                        curr[j]=prev[j]+prev[j-1];
                    }
                    else
                        curr[j]=prev[j];
                }
            }
            prev=curr;
        }
        
        return curr[n];
    }
};