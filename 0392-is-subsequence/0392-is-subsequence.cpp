class Solution {
public:
    bool solve(string s, string t,int i,int j, int m, int n){
        
        if(i==m)
            return 1;
        if(j==n)
            return 0;
        
        
        if(s[i]==t[j])
            return solve(s,t,i+1,j+1,m,n);
        else 
            return solve(s,t,i,j+1,m,n);
    }
    
    
    bool isSubsequence(string s, string t) {
        
        int m=s.size();
        int n=t.size();
        if(m>n)
            return false;
        return solve(s,t,0,0,m,n);
    }
};