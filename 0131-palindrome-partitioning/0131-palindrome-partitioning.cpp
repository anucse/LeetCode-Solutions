class Solution {
public:
    
    vector<vector<string>> ans;
    vector<string> temp;
    
    bool palindrome(string s,int i, int j){
        
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        
        return true;
    }
    
    void solve(string s, int n,int i){
        
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        
        for(int j=i;j<n;j++){
            if(palindrome(s,i,j)){
                temp.push_back(s.substr(i,j-i+1));
                solve(s,n,j+1);
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        
        int n=s.size();
        solve(s,n,0);
        return ans;
    }
};