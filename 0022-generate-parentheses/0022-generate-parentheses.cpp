class Solution {
public:
    vector<string> ans;
    void solve(int n, string temp,int open, int close){
        if(open==n && close==n){
            ans.push_back(temp);
            return;
        }
        
        if(open<n){
            
            solve(n,temp+'(',open+1,close);
        }
        if(close<open){
            solve(n,temp+')',open,close+1);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        solve(n,"",0,0);
        return ans;
    }
};