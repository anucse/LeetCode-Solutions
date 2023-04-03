class Solution {
public:
    int ans;
    bool palindrome(string s){
        
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
           
        }
        
        return true;
    }
    void solve(string s,int n){
        ans=n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(palindrome(s.substr(i,j-i+1)))
                    ans++;
            }
        }
        
        
    }
    int countSubstrings(string s) {
        solve(s,s.size());
        return ans;
    }
};