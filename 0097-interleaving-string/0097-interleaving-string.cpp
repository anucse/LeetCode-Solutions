class Solution {
public:
    bool solve(vector<vector<int>>& dp, string s1, string s2, string s3, int n1, int n2, int n3, int i, int j, int k){
        
        bool match=false;
        if(k==n3)
            return true;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i<n1 && s1[i]==s3[k])
            match= match || solve(dp,s1,s2,s3,n1,n2,n3,i+1,j,k+1); 
        if(j<n2 && s2[j]==s3[k])
            match= match || solve(dp,s1,s2,s3,n1,n2,n3,i,j+1,k+1);
        
        return dp[i][j]=match;
        
        
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        
        if(n1+n2 != n3 )
            return false;
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        
        return solve(dp,s1,s2,s3,n1,n2,n3,0,0,0);
        
       
        
    }
};